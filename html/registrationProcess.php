<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Registration Process</title>
</head>
<body background="3.jpg" style="background-image: image()">
    <table border="1" height="1px" width="100%" >
        <tr>
            <td></td>
        </tr>
    </table>

    <table height="100px" style="color: blue" width="100%" >
        <tr>
            <td><img src="liclogo.svg" height="100px" width="200px" alt="logo"></td>
            <td><center><h1>Online Policy Management System</h1></center></td>
            <td><span>Login   </span><span>Register  </span></td>
        </tr>

    </table>
    <table border="1" height="1px" width="100%" >
        <tr>
            <td></td>
        </tr>
    </table>
    <marquee>New updates:Insurance Policy</marquee>
    <table style="margin-right: auto; margin-left:auto">
            <tr >
                <td><b>|  HOME  </b></td>
                <td><b>|  SERVICES  </b></td> 
                <td><b>|  CONTACT US  </b></td> 
                <td><b>|  ABOUT US  |</b></td> 
            </tr>
        </table>
    <h2 style="text-align:center">Registration Details</h2>
<table style="align-content: center;margin-left:auto;margin-right:auto;" height="300px" width="400px" >
    <tr>
        <td><b>First Name :</b></td>
        <td>
            <?php echo $_POST["fname"] ?>
        </td>
    </tr>

    <tr>
        <td><b>Middle Name :</b></td>
        <td>
            <?php echo $_POST["mname"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>Last Name :</b></td>
        <td>
            <?php echo $_POST["lname"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>Nominee Name :</b></td>
        <td>
            <?php echo $_POST["nname"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>Nominee Relation :</b></td>
        <td>
            <?php echo $_POST["nrelation"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>Date of Birth :</b></td>
        <td>
            <?php echo $_POST["dob"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>Gender :</b></td>
        <td>
            <?php echo $_POST["genderData"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>Email:</b></td>
        <td>
            <?php echo $_POST["email"] ?>
        </td>
    </tr>

    <tr>
        <td><b>Address :</b></td>
        <td>
            <?php echo $_POST["address"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>City :</b></td>
        <td>
            <?php echo $_POST["city"] ?>
        </td>
    
    </tr>

    <tr>
        <td><b>State :</b></td>
        <td>
            <?php echo $_POST["state"] ?>
        </td>
    
    </tr>

    
</body>
</html>