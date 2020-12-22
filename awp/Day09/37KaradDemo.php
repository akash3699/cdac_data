<?php 
    if(!isset($_GET["btnRegister"]))
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
<?php echo "Welcome " .  $_GET["EName"];?><br>
<?php echo "Age is " .   $_GET["EAge"] ; ?><br>
<?php echo "EMail is " .   $_GET["EMail"] ;?><br>
</body>
</html>