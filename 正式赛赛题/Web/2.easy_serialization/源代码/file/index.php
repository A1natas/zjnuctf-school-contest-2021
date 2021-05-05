<?php
error_reporting(0);
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