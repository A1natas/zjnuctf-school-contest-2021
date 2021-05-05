<?php

if(isset($_GET['file'])){
    echo("你可以尝试些什么，比如明日方舟？");
    $file = $_GET['file'];
    if(preg_match('/php|data|phar|zip/i', $file)){
        die('嘟嘟噜，诶？真由理的怀表怎么停了，明明上过发条的吖！');
    }else{
        include($file);
    }

}
else{
    $url = 'http://'.$_SERVER['SERVER_NAME'].':'.$_SERVER["SERVER_PORT"].$_SERVER["REQUEST_URI"].'?file=picture.html';
    Header("Location:$url");
}
?>
