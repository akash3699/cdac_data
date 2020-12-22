<?php

    session_start();
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];
    }
    else
    {
        header("location:login.php");

    }



?>


<!DOCTYPE html>
<html lang="en">
<head>
    <title>Dashboard</title>
    <link rel="stylesheet" href="bootstrap.css">
    <script src="jquery-3.4.1.js"></script>
    <!-- <script src="jquery-1.8.3.js"></script> -->
    <script src="bootstrap.js"></script>
    <script>
       
        
       
    </script>
</head>
<body>
    <a href="logout.php">Logout</a>
    <br>    
        <a href="addnewrecord.php">Add New Record</a>
    <br>

    <table class="table">
        <?php
        
        $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");

        $ResultSet=   mysqli_query($connectionToDB,"select * from student") ;
   
           while($currentRow= 
                   mysqli_fetch_row($ResultSet) )
           {?>
               <tr>
                   
                   <td><?php echo  $currentRow[0] ?></td>
                   <td><?php echo  $currentRow[1] ?></td>
                   <td><?php echo  $currentRow[2] ?></td>
                   <td><input type="button"  id="btnUpdateRecord" name="btnUpdateRecord" onclick='location.href="http://localhost/updateRecord.php?ROLL=<?php  echo  $currentRow[0]  ?>"' value="Update"></td>
                   <td><input type="button"  id="btnDeleteRecord" name="btnDeleteRecord" onclick='location.href="http://localhost/deleteRecord.php?ROLL=<?php  echo  $currentRow[0]  ?>"' value="Delete"></td>
                   
              </tr>
           <?php }
                mysqli_close($connectionToDB);
    ?>


    </table>

    
</body>
</html>