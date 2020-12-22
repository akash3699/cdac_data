<?php
    $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
    $query= "select * from student where rollno='".$_GET["ROLL"]."'";
    // echo $query;
    $checkrecord= mysqli_query($connectionToDB,$query);
    $noofRows= mysqli_num_rows($checkrecord);
    $allrow;
    header("Content-Type:application/json");
    if($noofRows>0)
    {
        $allrow=mysqli_fetch_all($checkrecord);

        echo json_encode($allrow);
    }
    else
    {
        
    }
    mysqli_close($connectionToDB);

?>