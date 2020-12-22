const express = require("express");
const config = require("config");
const app = express();
const empRouter=require("./routes/emp");
var connection;
const mysql      = require('mysql');

var myData=[];
const port = parseInt(config.get("port"));

app.use(express.json());
app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Methods", "GET,POST,PUT,DELETE");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
});
app.use("/emp",empRouter);
// app.get("/",function(request,response){

//     response.send("Welcome Home");
// });

app.all('/', function (req, res) {
    res.send('Accessing the secret section ...');
  })


app.listen(port,function(){
    console.log("Server Started on port " + port);
});
