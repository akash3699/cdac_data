const express = require("express");
const app=express();

var mydata=[{"CourseId":"1001","CourseName":"PG-DAC","Fees":"90000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1002","CourseName":"PG-DMC","Fees":"90000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1003","CourseName":"PG-DESD","Fees":"90000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1004","CourseName":"PG-DBDA","Fees":"115000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1005","CourseName":"PG-DASDM","Fees":"80000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]}];


app.get("/",function(request,response){
    response.content-Type("text/html");
    response.send("Welcome Home");

});

app.get("/empdata",function(request,response){
    response.contentType("application/json");
    response.send(JSON.stringify(mydata));

});




app.listen(35353,function(){

    console.log("Server Started");
});