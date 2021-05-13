#! python3
#coding=utf-8

def shit16_encode(string):
    shit = "压力马斯内!"
    for i in string:
        temp = bin(ord(i))[2:]
        temp = '0' * (16 - len(temp)) + temp
        shit += temp.replace('0', '哼').replace('1', '啊')
    return shit

flag = str(input())
print(shit16_encode(flag))