<?php

    session_start();
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

       
        // if(!isset($_POST["btnUpdateRecord"]))
        // {
        //     header("location:dashboard.php");
        // }

        if(isset($_POST["btnUpdate"]))
        {
            $rollno=$_POST["txtRollno"];
            $Name=$_POST["txtName"];
            $Email=$_POST["txtEmail"];

            $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
            $query= "update student set name='".$Name."', email='".$Email."' where rollno=".$rollno;
            echo $query;
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

<!DOCTYPE html>
<html lang="en">
<head>
   <title>Add New Record</title>
   <link rel="stylesheet" href="bootstrap.css">
    <script src="jquery-3.4.1.js"></script>
    <script src="bootstrap.js"></script>
</head>
<body>
    <a href="logout.php">Logout</a>
    <br>    
        <a href="dashboard.php">Go Back to Dashboard</a>
    <br>
    <form action="updateRecord.php" method="POST">
    <table class="table">

    <?php



    

    $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
    $ROLLid=$_GET["ROLL"];
    $query= "select * from student where rollno=".$ROLLid;
    //echo $query;
    $selectrecord= mysqli_query($connectionToDB,$query);
    $numRows= mysqli_affected_rows($connectionToDB);
    if($temp=mysqli_fetch_row($selectrecord))
    {
    session_start();
    $_SESSION["rollno"]=$temp[0];
    $_SESSION["Name"]=$temp[1];
    $_SESSION["Email"]=$temp[2];

    

?>
        <tr>
            <td>Roll No <input type="number" value=<?php  echo $_SESSION["rollno"]; ?> required="required" name="txtRollno" ></td>
        </tr>

        <tr>
            <td>Name <input type="text" name="txtName" value="<?php session_start(); echo $_SESSION["Name"];  ?>" required="required" ></td>
        </tr>
        <tr>
            <td>Email <input type="text" name="txtEmail" value="<?php session_start(); echo $_SESSION["Email"]; ?>" required="required" ></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" id="btnUpdate" name="btnUpdate" value="Update Record" ></td>
        </tr>
    <?php 
        mysqli_close($connectionToDB);
        } ?>
    
    </table>

    </form>
    
</body>
</html>