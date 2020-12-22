<?php

    session_start();
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

        if(isset($_POST["btnAddRecord"]))
        {
            $rollno=$_POST["txtRollno"];
            $Name=$_POST["txtName"];
            $Email=$_POST["txtEmail"];

            $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
            $query= "insert into student values(".$rollno.",'".$Name."','".$Email."')";
            // echo $query;
            $addrecord= mysqli_query($connectionToDB,$query);
            $numRows= mysqli_affected_rows($connectionToDB);

            if($numRows > 0)
            {
                echo "<br><h6>Success</h6>";
            }
            else
            {
                echo "<br><h6>Failed!</h6>";
            }

            mysqli_close($connectionToDB);

        }


    }
    else
    {
        header("location:login.php");

    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
   <title>Add New Record</title>
   <link rel="stylesheet" href="bootstrap.css">
    <script src="jquery-3.3.1.js"></script>
    <script src="bootstrap.js"></script>
</head>
<body>
    <a href="logout.php">Logout</a>
    <br>    
        <a href="dashboard.php">Go Back to Dashboard</a>
    <br>
    <form action="addnewrecord.php" method="POST">
    <table class="table">
        <tr>
            <td>Roll No <input type="number" required="required" name="txtRollno" ></td>
        </tr>

        <tr>
            <td>Name <input type="text" name="txtName" required="required" ></td>
        </tr>
        <tr>
            <td>Email <input type="text" name="txtEmail" required="required" ></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" name="btnAddRecord" value="Add New Record" ></td>
        </tr>
    </table>

    </form>
    
</body>
</html>