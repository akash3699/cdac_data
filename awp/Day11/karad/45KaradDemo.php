<?php
    $nameToBeSearched = $_GET["Name"];
    $connectionToDb= mysqli_connect("localhost","root","manager","karaddb");

    $query= "select * from Emp where Name='" .$nameToBeSearched . "'";

    $resultset= mysqli_query($connectionToDb, $query);

    $noofrows= mysqli_num_rows($resultset);

    header("Content-Type:application/json");
    if($noofrows > 0)
    {
        echo '{"result" : "taken"}';
    }
    else
    {
        echo '{"result" : "available"}';
    }
    mysqli_close($connectionToDb);
?>
