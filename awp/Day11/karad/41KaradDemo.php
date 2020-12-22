<?php 
    session_start();
    unset($_SESSION["uname"]);
    header("location:40KaradDemo.php")
?>