<?php
    if(!isset($_POST["btnRegister"]))
    {
        header("location:36KDemo.php");

        if(!isset($_POST["antiForgeryToken"]))
        {
            header("location:36KDemo.php");

        }
    }






?>


<!DOCTYPE html>
<html lang="en">
<head>
    <script src="jquery-3.4.1.min.js"></script>
    
    <title>Data</title>
</head>
<body>


    
    <table>
        <tr>
            <td>Name  <?php echo $_POST["txtName"]; ?>
            
            </td>
        </tr>
        <tr>
            <td>Age  <?php echo $_POST["txtAge"]; ?>
            
            </td>
        </tr>
        <tr>
            <td>Email <?php echo $_POST["txtEmail"]; ?>
            
            </td>
        </tr>
    </table>





</body>
</html>