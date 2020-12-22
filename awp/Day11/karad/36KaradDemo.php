<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <script src="jquery-3.4.1.min.js"></script>
    <script src="MPValidation.js"></script>
    <title>Document</title>
</head>
<body>
    <form action="37KaradDemo.php" method="POST">
            <input type="hidden" name="antiForgeryToken" id="antiForgeryToken" value="<?php echo "123"; ?>">
            <br>
            <table>
                    <tr>
                        <td>Name</td>
                        <td><input required="required" type="text" name="EName" id="txtName"></td>
                    </tr>
                    <tr>
                        <td>Age</td>
                        <td><input type="number" name="EAge" id="txtAge"></td>
                    </tr>
                    <tr>
                        <td>EMail</td>
                        <td><input type="email" required="required" name="EMail" id="txtEMail"></td>
                    </tr>
                        <tr>
                            <td>
                                <input type="submit" name="btnRegister" id="btn" value="Register Here">
                            </td>
                        </tr>
                </table>
    </form>
</body>
</html>