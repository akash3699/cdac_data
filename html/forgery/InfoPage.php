<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Info Page</title>
</head>
<body >

    <form  action="Debit.php" method="POST">
    <table style="align-content: center;margin-left:auto;margin-right:auto;" height="200px" width="400px">
    <tr>
        <td>Account No</td>
    </tr>
    <tr>
        <td><input type="number" name="acno" id="ACNO" required="required"></td>
    </tr>
    <tr>
        <td>Amount to debit</td>
    </tr>
    <tr>
        <td><input type="number" name="amtdebit" min=1 max=1000 id="AMTDEBIT" required="required"></td>
    </tr>

    <tr><td><input type="submit" name="btndebit" id="BTNDEBIT" value="Debit"></td></tr>


    </table>
    </form>
    
</body>
</html>