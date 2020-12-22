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
connection.connect();

app.get("/",function(request, response){
    response.send("Hello from express based server");
});


app.get("/api/emps",function(request, response){

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

app.get("/api/emps/:No",function(request, response){
    console.log("You searched for " + request.params.No);
    var empSearched= myData[ parseInt(request.params.No) - 1];
    // response.contentType("application/json");
    console.log(empSearched);
});



app.listen(50000, function(){
    console.log("Express based server started ...");
});

