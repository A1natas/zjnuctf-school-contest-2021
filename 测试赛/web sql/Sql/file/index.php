<!DOCTYPE html>
<html>
<head>
    <title>phpweb</title>
    <style type="text/css">
        body {
            background: url("bj.png") no-repeat;
            background-size: 100%;
        }
        p {
            color: white;
        }
        
    </style>
</head>

<body>
<script language=javascript>
    setTimeout("document.form1.submit()",5000)
</script>

<?php
error_reporting(0);
$con = mysqli_connect("127.0.0.1","ubuntu","ubuntu","ctf");
if (!isset($_GET['id'])){
	Header("Location:?id=1");
}
$id = $_GET['id'];
if(preg_match("/ /order/i",$id)){
    die("<script>alert('Stop hacking!')</script>");
}

$req = "select * from users where id=$id;";
$result=mysqli_query($con,$req);
$row = mysqli_fetch_all($result);
// var_dump($row);
// if ($row[0]){
// 	echo "<center><h1>猜猜flag在哪~</h1></center><br/>";
// }else{
// 	echo "<center>长脑子的没，密码都输不对？</center><br/>";
// }
// $result=$con->query($req);
// $row = $result -> fetch_all();
echo "<center><font color='white'>".$row[0][0]."</font></br>";
echo "<font color='white'>".$row[0][1]."</font></br>";
echo "<font color='white'>".$row[0][2]."</font></center>";
?>


