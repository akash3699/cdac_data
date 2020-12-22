<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
    <link rel="stylesheet" href="bootstrap.min.css">
    <script src="jquery-3.3.1.min.js"></script>
    <script src="bootstrap.min.js"></script>
    <script>
        $(document).ready(function(){
            $.ajax({
                url:"47KaradDemo.php",
                type:"GET",
                contentType: "application/json",
                success:function(result){
                    debugger    ;
                    for(i=0; i < result.length; i++)
                    {
                        var row = "<tr>";
                        for(j=0; j <result[i].length; j++)
                        {
                            row = row + "<td>" + result[i][j] + "</td>";
                        }
                        row = row + "<td><a href='43KaradDemo.php?No='" + result[i][0]  + ">Edit</a></td>";
                        row = row + "<td><a href='44KaradDemo.php?No='" + result[i][0]  + ">Delete</a></td>";
                        row = row + "</tr>";
                        debugger    ;
                        $("#myTable").append(row);
                    }
                },
                error:function(err){
                    debugger;
                }
            });
        });
    </script>
</head>
<body>
    <a href="41KaradDemo.php">Logout</a>
    <br>    
        <a href="42KaradDemo.php">Add New Record</a>
    <br>
    <table border="1" class="table" id="myTable">

    
    </table>
</body>
</html>












