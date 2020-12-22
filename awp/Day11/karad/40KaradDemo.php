<?php 
    session_start();
    
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];


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
    <a href="41KaradDemo.php">Logout</a>
    <br>    
        <a href="42KaradDemo.php">Add New Record</a>
    <br>
    <table border="1" class="table">

    <?php 
      
     $connectionToDB=   mysqli_connect("localhost","root", "manager","karaddb");

     $ResultSet=   mysqli_query($connectionToDB,"select * from Emp") ;

        while($currentRow= 
                mysqli_fetch_row($ResultSet) )
        {?>
            <tr>
                <td><?php echo  $currentRow[0] ?></td>
                <td><?php echo  $currentRow[1] ?></td>
                <td><?php echo  $currentRow[2] ?></td>
                <td><?php echo  '<a href="43KaradDemo.php?No=' . $currentRow[0] .'">Edit</a>' ?></td>
                <td><?php echo  '<a href="44KaradDemo.php?No=' . $currentRow[0] .'">Delete</a>' ?></td>
           </tr>
        <?php }
             mysqli_close($connectionToDB);
    ?>
    </table>
</body>
</html>












