<!doctype html>
<html lang="zh-CN">
<head>

<title>教学综合信息服务平台</title>
<style type="text/css">
	span{
		font-size: 24px;
		color:#1069a4;
		font-family:arial;
	}
	.div-line{
		font: normal 24px/45px "microsoft YaHei";
		position: absolute;
		left:500px;
		border: 1px;
	}
	.footer{
		text-align: center;
		color: #8099af;
		font: normal 12px/20px microsoft YaHei;
		margin: 15px;
		bottom:100px;
		left:600px;
		position: absolute;
	}
	.picture{
		border:1px;
		position: relative;
		top:150px;
		left:450px;
	}


</style>
</head>

<body>
	<div class="div-line">
		<img src="logo.png" style="margin-top:20px">

		<span>教学综合信息服务平台</span>
	</div>
	<div class="picture">
		<img src="login.jpg" />
	</div>
	<div>
		<form  action="login.php" method="post">
			<h5>用户登录</h5>
			<img src="log_ic01.png" width="16" height="16">
			<input type="text" name="username" value="" placeholder="用户名" onblur="" autocomplete="off">
			<br>
			<img src="log_ic02.png" width="16" height="16">
			<input type="password" name="password" value="" placeholder="密码" onblur="" autocomplete="off">
			<br>
			<button type="submit" value="submit">登录</button>
		</form>
	</div>


<!-- footer --> 
<div class="footer">
	<p id>版权所有&copy; Copyright 1999-2017  正方软件股份有限公司　　中国·杭州西湖区紫霞街176号 互联网创新创业园2号301</p>
</div>

</body>

</html>
<?php
error_reporting(0);

session_start(); //  启动会话，这步必不可少
$admin = false;//  防止全局变量造成安全隐患

//  判断是否登陆
if (isset($_SESSION["admin"]) && $_SESSION["admin"] === true) {
    echo "<script>alert('登录成功！正在跳转...')</script>";
    echo '<script language=javascript>window.location.href="admin123.php"</script>';
} else {
    //  验证失败，将 $_SESSION["admin"] 置为 false
    $_SESSION["admin"] = false;
    echo("您无权访问，请登录");
}

