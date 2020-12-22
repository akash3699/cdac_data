<?php 

    if(!isset($_POST["antiForgeryToken"]))
    {
        header("location:36KaradDemo.html");
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    <?php echo "Token you carry is: " . $_POST["antiForgeryToken"]; ?>
<?php echo "Welcome " .  $_POST["EName"];?><br>
<?php echo "Age is " .   $_POST["EAge"] ; ?><br>
<?php echo "EMail is " .   $_POST["EMail"] ;?><br>
</body>
</html>