# bit_operation

![image-20210503131959487](C:\Users\Senpai\AppData\Roaming\Typora\typora-user-images\image-20210503131959487.png)

丢到ida看一下main函数。

先用scanf读入字符串，然后将字符串s用encode()函数加密，最后把s的加密结果和b比较，如果完全相同则返回nice，不相同则返回oh no！

重点在于encode函数

![image-20210503132113834](C:\Users\Senpai\AppData\Roaming\Typora\typora-user-images\image-20210503132113834.png)

将字符串传入，for循环到字符串长度为止。将a1[i]的字符转换为无符号8位int，再*16，相当于左移4位。再取a1[i]的高4位加上之前左移的结果。

英文字符长度八位二进制，例如A ： 0100 0001	详见ascii码表

将原符号的ascii值左移四位，相当于取了低四位，往后补四个0。

补完以后再取高1位相加，那实际上就是将高四位和第四位交换。

转换成16进制就能很清楚的看出来：

A ：0x41 左移4位后-> 0x10 加上高四位后-> 0x10+0x4 = 0x14

所以解密也很简单，只要再把每个字符的后四位和前4位交换一下即可。



## 再来看密文

因为程序最后会和b[]数组比较，所以密文肯定存在b数组里：

![image-20210503132855396](C:\Users\Senpai\AppData\Roaming\Typora\typora-user-images\image-20210503132855396.png)

![image-20210503132921030](C:\Users\Senpai\AppData\Roaming\Typora\typora-user-images\image-20210503132921030.png)

选中 shift E

![image-20210503132943377](C:\Users\Senpai\AppData\Roaming\Typora\typora-user-images\image-20210503132943377.png)

选择unsighed char array，复制下面的数据结果，即为密文数据。

exp

```c
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void encode(char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        uint8_t c = *(a + i);
        *(a + i) = (c << 4) + (c >> 4);
    }
}

int main()
{
    //首先逆向分析出b数组为密文,ida提取。
    char b[] = {102, 198, 22, 118, 183, 55, 134, 246, 87, 230,
                150, 150, 55, 22, 214, 22, 245, 86, 150, 86,
                230, 230, 246, 182, 22, 214, 150, 215,0};
    encode(b);
    printf("%s\n", b);
}
```

