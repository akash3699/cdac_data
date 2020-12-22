
<?php 
    if(isset($_POST["btnLogin"]))
    {
           if($_POST["UserName"] == "abc" 
                && $_POST["Password"]=="abc@123")
           {
             session_start();
             $_SESSION["uname"] = $_POST["UserName"];
             header("location:40KaradDemo.php");
             
           }
           else
           {
            echo "user Name or Password is not correct";
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
    <form action="39KaradDemo.php" method="POST">
            <br>
            <table>
                    <tr>
                        <td>User Name</td>
                        <td><input required="required" type="text" name="UserName" id="txtUName"></td>
                    </tr>
                    <tr>
                        <td>Password</td>
                        <td><input type="password" name="Password" id="txtPwd"></td>
                    </tr>
                        <tr>
                            <td>
                                <input type="submit" name="btnLogin" id="btn" value="Login">
                            </td>
                        </tr>
                </table>
    </form>
</body>
</html>