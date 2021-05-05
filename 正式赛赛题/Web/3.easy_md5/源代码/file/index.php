<?php
show_source(__FILE__);
error_reporting(0);
if($_GET['a1']!=$_GET['a2'] && md5($_GET['a1'])==md5($_GET['a2'])){ //第一关
	if($_GET['b1']!==$_GET['b2'] && md5($_GET['b1'])===md5($_GET['b2'])) //第二关
	{
		if (isset($_POST['cmd']) && $_POST['cmd']){ //第三关
			$cmd = $_POST['cmd'];
			if (preg_match("/flag|cat| |ls/i", $cmd)) {
    			die("hacker,go away!");
			}
			else{
				echo("最后一关了,がんばって");
				@eval($cmd);
			}
		}
	}
	else{
		echo file_get_contents("flag.txt");
	}
}
else
{
	echo("哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊啊<br>");
	echo "<img src=\"1.gif\"/>";
}

?>