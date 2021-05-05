<?php

session_start();/*开启会话*/
require "sql-connect.php";

if(isset($_POST['username']) && isset($_POST['password']))
{
	$uname=$_POST['username'];
	$passwd=$_POST['password'];

	if(preg_match('/\'| |=/i',$uname) || preg_match('/\'| |=/i',$passwd)){
		die("hacker!!!,nonono");
	}
	else
	{
	$sql="SELECT username, password FROM users WHERE username='$uname' and password='$passwd'";
	$result=mysqli_query($conn,$sql);
	$row = mysqli_num_rows($result);
	if($row)
		{
		echo("恭喜你登录成功,congratulations");
    		$_SESSION["admin"] = true;
    		echo '<script language=javascript>window.location.href="index.php"</script>';
		}
		else{
			die("登录失败, try again");
		}
	}
}

?>
