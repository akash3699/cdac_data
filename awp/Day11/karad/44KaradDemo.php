<?php 

    session_start();
    
    if(isset($_SESSION["uname"]))
    {
            if(isset($_GET["No"]))
            {
                $notobedeleted = $_GET["No"];
                $connectionToDb= mysqli_connect("localhost","root","manager","karaddb");

                $query= "delete from Emp where No=" .$notobedeleted;

                mysqli_query($connectionToDb, $query);

                mysqli_close($connectionToDb);

                header("location:40KaradDemo.php");
        }
    }   
    else
    {
        header("location:39KaradDemo.php");
    }
?>