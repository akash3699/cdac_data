<?php
    if(isset($_POST["btnLogin"]))
    {
        if($_POST["UserName"]=="asd" && $_POST["password"]=="asd")
        {
            session_start();
            $_SESSION["uname"]=$_POST["UserName"];
            header("location:dashboard.php");

        }
        else
        {
            echo "Incorrect Username or Password";
        }

    }
    else
    {
        echo "Login Here";
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
<form action="login.php" method="POST">

<input type="hidden" name="antiForgeryToken" id="antiForgeryToken" value="<?php echo "123"; ?>">
<table>
        <tr>
            <td>User Name
            <input type="text" name="UserName" id="inputUname" required="required" >
            </td>
        </tr>
        <tr>
            <td>Password
            <input type="password" name="password" id="inputpwd" required="required">
            </td>
        </tr>
        <tr>
            <td>
            <input type="submit" name="btnLogin" id="inputLogin" value="Login" >
            </td>
        </tr>
    </table>

</form>
</body>
</html>