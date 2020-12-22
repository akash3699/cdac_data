<?php
    $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
    $query= "select * from student where rollno='".$_GET["ROLL"]."'";
    // echo $query;
    $checkrecord= mysqli_query($connectionToDB,$query);
    $noofRows= mysqli_num_rows($checkrecord);
    header("Content-Type:application/json");
    if($noofRows>0)
    {
        echo '{"result":"taken"}';
    }
    else
    {
        echo '{"result":"available"}';
    }
    mysqli_close($connectionToDB);

?>