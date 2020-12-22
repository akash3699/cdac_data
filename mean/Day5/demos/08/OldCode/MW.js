var express = require("express");
var app =  express();
app.use(express.json());

app.use(function(request, response, next){
    console.log("In some code before reply...");
    next();
});

app.use(function(request, response, next){
    console.log("Inside Another Middleware");
    next();
});

app.post("/api/emps",function(request, response){
    console.log(request.body.Name);
    //response.send("you called employees");



});

app.get("/api/emps",function(request, response){

    response.send("you called employees");

});

app.listen(4000, function(){
    console.log("Server Started..");
})