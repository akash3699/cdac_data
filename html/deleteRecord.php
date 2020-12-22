<?php

    session_start();
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

       
        

        if(isset($_GET["ROLL"]))
        {
            
           

            $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
            $query= "DELETE FROM student where rollno=".$_GET["ROLL"];
            echo $query;
            $deleterecord= mysqli_query($connectionToDB,$query);
            $numRows= mysqli_affected_rows($connectionToDB);
            
            if($numRows > 0)
            {
                echo "<br><h6>Success</h6>";
            }
            else
            {
                echo "<br><h6>Failed!</h6>";
            }

            header("location:dashboard.php");

        }
        // else
        // {
        //     header("location:dashboard.php");
        // }


    }
    else
    {
        header("location:login.php");

    }
?>