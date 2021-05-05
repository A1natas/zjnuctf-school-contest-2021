---
typora-root-url: 图片
---

# 解题方法

发现是一个文件上传题，发现过滤了ph后缀和文件类型，看样子是不是过滤死了呢，其实可以使用.htaccess来绕过

首先上传一句话jpg文件，然后上传.htaccess并抓包

```
<FilesMatch "jpg">
SetHandler application/x-httpd-php
</FilesMatch>
```

![](https://files.catbox.moe/vodlzl.png)

一句话即可成功，可连接蚁剑

![](https://files.catbox.moe/hypcmk.png)

其实细心一点还可以发现robots.txt，发现hint.php，很明显的文件包含，直接包含我们上传的jpg

![](https://files.catbox.moe/v3e3oi.png)

