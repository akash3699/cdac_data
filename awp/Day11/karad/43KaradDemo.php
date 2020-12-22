<?php 

    $notobeedited = 0;
    $nametobeedited = "";
    $addresstobeedited = "";

    session_start();
    
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

        if(isset($_POST["btnUpdate"]))
        {
            $no = $_POST["txtNo"];
            $name = $_POST["txtName"];
            $address = $_POST["txtAddress"];

            $connectionToDb= mysqli_connect("localhost","root","manager","karaddb");

            $query= "update Emp set Name='" .$name. "', Address='". $address."' where No = " .$no;
            //echo $query;
            
            $result=mysqli_query( $connectionToDb, $query);

            $numRows= mysqli_affected_rows($connectionToDb);

            if($numRows > 0)
            {
                //echo "<br><h6>Success</h6>";
                header("location:40KaradDemo.php");
            }
            else
            {
                echo "<br><h6>Failed!</h6>";
            }
        }
        else{
            if(isset($_GET["No"]))
            {
                $notobeedited = $_GET["No"];
                $connectionToDb= mysqli_connect("localhost","root","manager","karaddb");

                $query= "select * from Emp where No=" .$notobeedited;

                $resultset= mysqli_query($connectionToDb, $query);

                $noofrows= mysqli_num_rows($resultset);

                if($noofrows > 0)
                {
                    $row =  mysqli_fetch_row($resultset);

                    $nametobeedited =  $row[1];
                    $addresstobeedited = $row[2];
                }
                else
                {
                    echo "Sorry! Record you are trying to find does not exist!";
                }
                mysqli_close($connectionToDb);


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
    <form action="43KaradDemo.php" method="POST">
        <a href="41KaradDemo.php">Logout</a>
        <br>    
            <a href="40KaradDemo.php">Go back to List</a>
        <br>

        <table border="1" class="table">
            <tr>
                <td>No</td>
                <td><input type="text" name="txtNo" value="<?php echo $notobeedited; ?>"></td>
            </tr>
            <tr>
                <td>Name</td>
                <td><input type="text" name="txtName" value="<?php echo $nametobeedited; ?>"></td>
            </tr>
            <tr>
                <td>Address</td>
                <td><input type="text" name="txtAddress" value="<?php echo $addresstobeedited; ?>"></td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center"><input type="submit" name="btnUpdate" value="Save Changes"></td>
            </tr>
        </table>

    </form>
    
</body>
</html>