<?php

session_start();

function curl($url){
	$ch=curl_init();
	curl_setopt($ch,CURLOPT_URL,$url);
	curl_setopt($ch,CURLOPT_HEADER,0);
	curl_exec($ch);
	curl_close($ch);
}

if(isset($_SESSION["admin"]) && $_SESSION["admin"] === true) {
	$url=$_GET['url'];
	if(empty($_GET['url'])){
		echo("?url=www.baidu.com");
	}
	curl($url);
}
else{
	die("你没有登录，混蛋");
}
?>
