<?php

    session_start();
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

        if(isset($_POST["btnAddRecord"]))
        {
            $rollno=$_POST["txtRollno"];
            $Name=$_POST["txtName"];
            $Email=$_POST["txtEmail"];

            $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
            $query= "insert into student values(".$rollno.",'".$Name."','".$Email."')";
            // echo $query;
            $addrecord= mysqli_query($connectionToDB,$query);
            $numRows= mysqli_affected_rows($connectionToDB);

            if($numRows > 0)
            {
                echo "<br><h6>Success</h6>";
            }
            else
            {
                echo "<br><h6>Failed!</h6>";
            }

            mysqli_close($connectionToDB);

        }


    }
    else
    {
        header("location:login.php");

    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
   <title>Add New Record</title>
   <link rel="stylesheet" href="bootstrap.css">
    <script src="jquery-3.4.1.js"></script>
    <script src="bootstrap.js"></script>
    <script>
        $(document).ready(function(){
            $("#txtEmail").blur(function(){
                $.ajax({
                    url:"emailCheck.php?EMAIL="+$(this).val(),
                    type:"GET",
                    contentType:"application/json",
                    success:function(ResponseFromServer){
                        if(ResponseFromServer.result=="taken")
                        {
                            $("#errtxtEmail").html("Email is already Added");
                            $("#errtxtEmail").css("color","red");
                            $("#btnAddRecord").attr("disabled","disabled");
                        }
                        else
                        {
                            $("#errtxtEmail").html("Email is available");
                            $("#errtxtEmail").css("color","green");
                            $("#btnAddRecord").removeAttr("disabled");
                        }

                    },
                    error:function(err){
                        
                        alert("Ajax call failed ...".err); 
                        
                        
                        
                    },

                });



            });

            $("#txtRollno").blur(function(){
                $.ajax({
                    url:"rollCheck.php?ROLL="+$(this).val(),
                    type:"GET",
                    contentType:"application/json",
                    success:function(ResponseFromServer){
                        if(ResponseFromServer.result=="taken")
                        {
                            $("#errtxtRoll").html("Roll No is already Added");
                            $("#errtxtRoll").css("color","red");
                            $("#btnAddRecord").attr("disabled","disabled");
                        }
                        else
                        {
                            $("#errtxtRoll").html("Roll No is available");
                            $("#errtxtRoll").css("color","green");
                            $("#btnAddRecord").removeAttr("disabled");
                        }

                    },
                    error:function(err){
                        
                        alert("Ajax call failed ...".err); 
                        
                        
                        
                    },

                });

                

            });


        });
    </script>
</head>
<body>
    <a href="logout.php">Logout</a>
    <br>    
        <a href="dashboard.php">Go Back to Dashboard</a>
    <br>
    <form action="addnewrecord.php" method="POST">
    <table class="table">
        <tr>
            <td>Roll No <input type="number" required="required" id="txtRollno" name="txtRollno" ><br><div id="errtxtRoll" ></div></td>
        </tr>

        <tr>
            <td>Name <input type="text" name="txtName" required="required" ></td>
        </tr>
        <tr>
            <td>Email <input type="text" id="txtEmail" name="txtEmail" required="required" ><br><div id="errtxtEmail" ></div></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" name="btnAddRecord" value="Add New Record" ></td>
        </tr>
    </table>

    </form>
    
</body>
</html>