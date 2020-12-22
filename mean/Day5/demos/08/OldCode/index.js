const mysql = require("mysql");
const express =  require("express");
const app =  express();
const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : 'manager',
    database : 'mydatabase'
  });

var myData =[];

app.get("/employees",function(request, response){
    connection.connect();
    
    connection.query("select * from emp", function(err, result){
        if(err==null)
        {
           myData =  result;
           response.contentType("application/json");
           response.send(JSON.stringify(myData));
        }
        else
        {
           response.send("Something went wrong!"); 
        }
    });
    
});

app.get("/employees/:No",function(request, response){
    console.log("You searched for " + request.params.No);
    var empSearched= myData[parseInt(request.params.No) - 1];
    response.contentType("application/json");
    response.send(empSearched);
});



app.listen(50000, function(){
    console.log("Express based server started ...");
});
