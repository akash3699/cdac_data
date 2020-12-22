<?php



echo $_SERVER['HTTP_HOST'];
if(strcmp($_SERVER['HTTP_REFERER'],"http://localhost/forgery/InfoPage.php"))
{
    header("location:fake.php");
}

    if(!isset($_POST["btndebit"]) )
    {
        header("location:InfoPage.php");
    }
?>



<!DOCTYPE html>
<html lang="en">
<head>
    <title>Balance Details</title>
</head>
<body>
    <table style="align-content: center;margin-left:auto;margin-right:auto;" height="200px" width="400px">
    <tr>
        <td><?php echo $_POST["amtdebit"] ?> INR Debited</td>
    </tr>
    <tr>
        <td> From Account  <?php echo $_POST["acno"] ?></td>
    </tr>
    <tr>
        <td>Balance Available in Account is <?php 
        $bal=1000; 
        $amt=$_POST["amtdebit"];
        $bal=$bal-$amt;
        echo $bal;
        ?> INR</td>
    </tr>
</table>
</body>
</html>