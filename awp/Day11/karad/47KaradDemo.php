<?php 

     $connectionToDB=   mysqli_connect("localhost","root", "manager","karaddb");

     $ResultSet=   mysqli_query($connectionToDB,"select * from Emp") ;

     $allRows = mysqli_fetch_all($ResultSet);

     header("Content-Type:application/json");
     echo json_encode($allRows);

     mysqli_close($connectionToDB);


?>