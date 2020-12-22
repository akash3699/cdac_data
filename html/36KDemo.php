<?php







?>


<!DOCTYPE html>
<html lang="en">
<head>
    <script src="jquery-3.4.1.min.js"></script>
    
    <title>Login</title>
</head>
<body>
<form action="37KDemo.php" method="POST">

<input type="hidden" name="antiForgeryToken" id="antiForgeryToken" value="<?php echo "123"; ?>">
<table>

        <tr>
            <td>Name
            <input type="text" name="txtName" id="inputName" required="required" >
            </td>
        </tr>
        <tr>
            <td>Age
            <input type="number" name="txtAge" id="inputAge" required="required" >
            </td>
        </tr>
        <tr>
            <td>Email
            <input type="email" name="txtEmail" id="inputEmail" required="required">
            </td>
        </tr>
        <tr>
            <td>
            <input type="submit" name="btnRegister" id="inputRegbtn" >
            </td>
        </tr>
    </table>

</form>


</body>
</html>