var config = require("config");
var express = require("express");
var adminRoutes= require("./routes/admin");
var empRoutes= require("./routes/emp");
var app =  express();

const port = parseInt(config.get("port"));


app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Methods", "GET,POST,PUT,DELETE");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
});

//Use Middleware
app.use(express.json());
app.use("/admin",adminRoutes);
app.use("/employees",empRoutes);




//listen to port for requests
app.listen(port, function(){
    console.log("Server Started on port  " + port );
})
