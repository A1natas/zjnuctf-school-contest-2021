#! python3
#coding=utf-8


def shit16_decode(string):
    string = string[6:].replace('哼','0').replace('啊','1')
    result = ""
    temp = ""
    for i in string:
        temp += i
        if len(temp) == 16:
            result += chr(int(temp,2))
            temp = ""
    return result

a = '压力马斯内!哼哼哼哼哼哼哼哼哼啊啊哼哼啊啊哼哼哼哼哼哼哼哼哼哼啊啊哼啊啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼啊哼哼哼哼哼哼哼哼哼啊啊哼哼啊啊啊哼哼哼哼哼哼哼哼哼啊啊啊啊哼啊啊哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊啊哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼哼哼啊啊哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼哼哼哼哼啊哼啊啊哼啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊啊哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼啊哼哼哼哼哼哼哼哼哼哼啊哼啊啊哼啊哼哼哼哼哼哼哼哼哼哼啊啊哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊哼哼哼哼哼哼哼哼哼哼啊啊啊哼哼哼哼哼哼哼哼哼哼哼哼哼啊哼啊啊哼啊哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊啊哼哼哼哼哼哼哼哼哼哼哼啊啊啊哼哼哼哼哼哼哼哼哼哼哼哼哼啊哼啊啊哼啊哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼啊啊哼哼哼哼哼哼哼哼哼哼啊啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼啊哼哼哼哼哼哼哼哼哼哼啊啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼啊啊哼啊啊啊哼哼哼哼哼哼哼哼哼啊啊哼哼啊哼哼哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼哼哼哼哼啊啊哼啊啊啊哼哼哼哼哼哼哼哼哼哼啊啊哼哼哼哼哼哼哼哼哼哼哼哼哼啊啊啊啊啊哼啊'

print(shit16_decode(a))