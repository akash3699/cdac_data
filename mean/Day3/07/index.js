const express =  require("express");
const app =  express();

var myData = 
[
    {No : 11, Name: "Mahesh1", Address: "Pune1"},
    {No : 12, Name: "Mahesh2", Address: "Pune2"},
    {No : 13, Name: "Mahesh3", Address: "Pune3"}
];


app.get("/",function(request, response){
    response.send("Hello from express based server");
});


app.get("/employees/show",function(request, response){
    response.contentType("application/json");
    response.send(JSON.stringify(myData));
});


app.post("/employees/show",function(request, response){
    
});



app.listen(5000, function(){
    console.log("Express based server started ...");
});

