<?php

    $rollno=0;
    $Name="";
    $Email="";

    session_start();
    if(isset($_SESSION["uname"]))
    {
        echo "Welcome " . $_SESSION["uname"];

       
        // if(!isset($_POST["btnUpdateRecord"]))
        // {
        //     header("location:dashboard.php");
        // }

        if(isset($_POST["btnUpdate"]))
        {
            $rollno=$_POST["txtRollno"];
            $Name=$_POST["txtName"];
            $Email=$_POST["txtEmail"];

            $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
            $query= "update student set name='".$Name."', email='".$Email."' where rollno=".$rollno;
            echo $query;
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
            header("location:dashboard.php");

        }
        // else
        // {
        //     header("location:dashboard.php");
        // }


    }
    else
    {
        header("location:login.php");

    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
   <title>Update Record</title>
   <link rel="stylesheet" href="bootstrap.css">
    <script src="jquery-3.4.1.js"></script>
    <script src="bootstrap.js"></script>
    <script>
        $(document).ready(function(){
            $("#txtRollno").blur(function(){
        $.ajax({
            url:"rollChecktakealldata.php?ROLL="+$(this).val(),
            type:"GET",
            contentType:"application/json",
            success:function(ResponseFromServer){
                
                if(ResponseFromServer.length==1)
                {
                    $("#txtName").val(ResponseFromServer[0][1]);
                    $("#txtEmail").val(ResponseFromServer[0][2]);
                    $("#errtxtRollno").html(" found");
                    $("#btnUpdate").removeAttr("disabled");
                }
            },

            error:function(err){   
                if(err)
                {
                    
                    $("#txtName").val("");
                    $("#txtEmail").val("");
                    $("#errtxtRollno").html("not found");
                    $("#btnUpdate").attr("disabled","disabled");

                }
                
               
            }
            

        });

        

    });

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
                            $("#btnUpdate").attr("disabled","disabled");
                        }
                        else
                        {
                            $("#errtxtEmail").html("Email is available");
                            $("#errtxtEmail").css("color","green");
                            $("#btnUpdate").removeAttr("disabled");
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
    <form action="updateRecord.php" method="POST">
    <table class="table">

    <?php



    

    $connectionToDB=   mysqli_connect("localhost","root", "manager","sample1");
    $ROLLid=$_GET["ROLL"];
    $query= "select * from student where rollno=".$ROLLid;
    //echo $query;
    $selectrecord= mysqli_query($connectionToDB,$query);
    $numRows= mysqli_affected_rows($connectionToDB);
    if($temp=mysqli_fetch_row($selectrecord))
    {
    session_start();
    $rollno=$temp[0];
    $Name=$temp[1];
    $Email=$temp[2];

    

?>
        <tr>
            <td>Roll No <input type="number" id="txtRollno" value=<?php  echo $rollno ?> required="required" name="txtRollno" ><br><div id="errtxtRoll" ></div></td>
        </tr>

        <tr>
            <td>Name <input type="text" id="txtName" name="txtName" value="<?php echo $Name;  ?>" required="required" ></td>
        </tr>
        <tr>
            <td>Email <input type="email" id="txtEmail" name="txtEmail" value="<?php echo $Email; ?>" required="required" ><br><div id="errtxtEmail" ></div></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" id="btnUpdate" name="btnUpdate" value="Update Record" ></td>
        </tr>
    <?php 
        mysqli_close($connectionToDB);
        } ?>
    
    </table>

    </form>
    
</body>
</html>