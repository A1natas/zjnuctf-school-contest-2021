#! python3
#coding=gbk

def shit_plus_encode(string):
    shit_words = ['114','514','1919','810']
    shit = "やりますね!!"
    num_list = []
    for i in string:
        temp = bin(ord(i))[2:]
        temp = '0' * (16 - len(temp)) + temp
        num_list.append(temp)
    num_string = ""
    for i in range(len(num_list)):
        high_bytes = num_list[i][:8]
        low_bytes = num_list[i][8:]
        new_num = bin(int(num_list[i][:8],2) ^ int(num_list[i][8:],2))[2:]
        temp = new_num + low_bytes
        num_string += '0' * (16 - len(temp)) + temp
    temp = ""
    for i in num_string:
        temp += i
        if len(temp) ==2:
            shit += shit_words[int(temp,2)]
            temp = ""
    return shit

flag = r"***************"
print(shit_plus_encode(flag))
