from pwn import *

io = remote("121.43.169.147", 8848)

io.sendlineafter("choice : ", "1")
io.sendlineafter("judger name: ", "1")
io.sendlineafter("judger type: ", "1")

io.sendlineafter("choice : ", "2")
for i in range(18):
    rectmp = io.recvuntil("below input:").decode()
    inp = io.recvuntil("Your Answer (Time limit 5s):", drop=True)
    solver = process("./wqt_judger_acm/solves")
    solver.sendline(inp)
    res = solver.recvuntil("\n", drop=True)
    print(res)
    io.sendline(res)
io.interactive()
