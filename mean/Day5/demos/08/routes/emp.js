const mysql = require("mysql");
var express = require("express");
var Joi =require("joi");
var emprouter =  express();

const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : 'manager',
    database : 'mydatabase'
  });

var myData =[];
connection.connect();

function validate(bodyContent)
{
    const schema = {
        "name": Joi.string().length(6).required(),
        "no": Joi.number().required(),
        "address": Joi.required()
        };
   return Joi.validate(bodyContent , schema);
}

emprouter.post("/",function(request, response){

    let resultOfValidation= validate(request.body);
    console.log(request.body);
    if(resultOfValidation.error==null)
{
    let eno = parseInt(request.body.no);
    let ename = request.body.name;
    let eddress = request.body.address; 
    
    let query = `insert into emp values(${eno}, '${ename}', '${eddress}')`;
    console.log(query);

    connection.query(query, function(err, result){
        if(err==null)
        {
           response.contentType("application/json");
           response.send(JSON.stringify(result));
        }
        else
        {
           response.contentType("application/json");
           response.send(err); 
        }
    });
}
else{
    response.contentType("application/json");
    response.send(JSON.stringify(resultOfValidation));
}       
});


emprouter.put("/:No",function(request, response){
    let eno = parseInt(request.params.No);
    let ename = request.body.name;
    let eddress = request.body.address; 
    
    let query = `update emp set name= '${ename}',address= '${eddress}' where no=${eno}`;
    console.log(query);

    connection.query(query, function(err, result){
        if(err==null)
        {
           response.contentType("application/json");
           response.send(JSON.stringify(result));
        }
        else
        {   
           response.contentType("application/json");
           response.send(err); 
        }
    });
        
});

emprouter.delete("/:No",function(request, response){
    let eno = parseInt(request.params.No);
    let query = `delete from emp where no=${eno}`;
    console.log(query);

    connection.query(query, function(err, result){
        if(err==null)
        {
           response.contentType("application/json");
           response.send(JSON.stringify(result));
        }
        else
        {
           response.contentType("application/json");
           response.send(err); 
        }
    });
        
});



emprouter.get("/", function(request, response){
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

emprouter.get("/:No", function(request, response){
    connection.query("select * from emp where no="+request.params.No, function(err, result){
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

module.exports = emprouter;
