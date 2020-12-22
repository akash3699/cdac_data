<?php 
    session_start();
    
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

        if(isset($_POST["btnAdd"]))
        {
            $no = $_POST["txtNo"];
            $name = $_POST["txtName"];
            $address = $_POST["txtAddress"];

            $connectionToDb= mysqli_connect("localhost","root","manager","karaddb");

            //$query= "insert into Emp values(3,'Mahesh', 'Pune')";
            $query= "insert into Emp values(" . $no . ",'".$name."', '".$address."')";
            //echo $query;
            
            $result=mysqli_query( $connectionToDb, $query);

            $numRows= mysqli_affected_rows($connectionToDb);

            if($numRows > 0)
            {
                echo "<br><h6>Success</h6>";
            }
            else
            {
                echo "<br><h6>Failed!</h6>";
            }
        }
    }
    else
    {
        header("location:39KaradDemo.php");
    }
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
    <link rel="stylesheet" href="bootstrap.min.css">
    <script src="jquery-3.3.1.min.js"></script>
    <script src="bootstrap.min.js"></script>
</head>
<body>
    <form action="42KaradDemo.php" method="POST">
        <a href="41KaradDemo.php">Logout</a>
        <br>    
            <a href="40KaradDemo.php">Go back to List</a>
        <br>

        <table border="1" class="table">
            <tr>
                <td>No</td>
                <td><input type="text" name="txtNo"></td>
            </tr>
            <tr>
                <td>Name</td>
                <td><input type="text" name="txtName"></td>
            </tr>
            <tr>
                <td>Address</td>
                <td><input type="text" name="txtAddress"></td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center"><input type="submit" name="btnAdd" value="Add New Record"></td>
            </tr>
        </table>

    </form>
    
</body>
</html>