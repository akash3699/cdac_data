const mysql= require("mysql");
const Joi= require("joi");
const express=require("express");
const empRouter=express();

empRouter.get("/",function(request,response){
    connection = mysql.createConnection({
        host     : 'localhost',
        user     : 'root',
        password : 'manager',
        database : 'db1'
      });
    connection.connect();
    connection.query("select * from db1.test",function(err,result){
        if(err==null)
        {
            myData=result;
            response.contentType("application/json");
            response.send(JSON.stringify(myData));
            connection.end();

        }
        else
        {
            response.contentType("text/html");
            response.send("something went wrong");
        }
        

    });

     
    
});

function validate(bodyContent)
{
    
    const schema={
        "name":Joi.string().length(6).required(),
        "no":Joi.number().required(),
        "address":Joi.required()
    };

    return Joi.validate(bodyContent,schema);

}

empRouter.post("/",function(request,response){
    console.log(request.body);
    
    let resultofvalidation=validate(request.body);

    if(resultofvalidation.error==null)
    {
        connection = mysql.createConnection({
            host     : 'localhost',
            user     : 'root',
            password : 'manager',
            database : 'db1'
          });
        connection.connect();
    
        let No=request.body.no;
        let Name = request.body.name;
        let Address = request.body.address;
        let query1=`insert into db1.test values (${No},'${Name}','${Address}')`;
        console.log(query1);
        connection.query(query1,function(err,result){
            if(err==null)
            {
                myData=result;
                response.contentType("application/json");
                response.send(JSON.stringify(myData));
                connection.end();
    
            }
            else
            {
                response.contentType("text/html");
                response.send(err);
            }
                
    
        });
    }
    else
    {   
        response.contentType("text/html");
        response.send(resultofvalidation.err);

    }

});

empRouter.get("/:No",function(request,response){
    console.log(request.body);
    
    connection = mysql.createConnection({
        host     : 'localhost',
        user     : 'root',
        password : 'manager',
        database : 'db1'
      });
    connection.connect();

    let No=request.params.No;
    // let Name = request.body.name;
    // let Address = request.body.address;
    let query1=`select * from db1.test where no=${No}`;
    console.log(query1);
    connection.query(query1,function(err,result){
        if(err==null)
        {
            myData=result;
            response.contentType("application/json");
            response.send(JSON.stringify(myData));
            connection.end();

        }
        else
        {
            response.contentType("text/html");
            response.send("something went wrong");
        }
        

    });

    
});

empRouter.put("/:no",function(request,response){
    console.log(request.body);
    
    connection = mysql.createConnection({
        host     : 'localhost',
        user     : 'root',
        password : 'manager',
        database : 'db1'
      });
    connection.connect();

    let No=request.params.no;
    let Name = request.body.name;
    let Address = request.body.address;
    let query1=`update db1.test set name='${Name}',address='${Address}' where no=${No}`;
    console.log(query1);
    connection.query(query1,function(err,result){
        if(err==null)
        {
            myData=result;
            response.contentType("application/json");
            response.send(JSON.stringify(myData));
            connection.end();

        }
        else
        {
            response.contentType("text/html");
            response.send("something went wrong");
        }
        

    });

     
    
});

empRouter.delete("/:no",function(request,response){
    console.log(request.body);
    
    connection = mysql.createConnection({
        host     : 'localhost',
        user     : 'root',
        password : 'manager',
        database : 'db1'
      });
    connection.connect();

    let No=request.params.no;
    // let Name = request.body.name;
    // let Address = request.body.address;
    let query1=`delete from db1.test where no=${No}`;
    console.log(query1);
    connection.query(query1,function(err,result){
        if(err==null)
        {
            myData=result;
            response.contentType("application/json");
            response.send(JSON.stringify(myData));
            connection.end();

        }
        else
        {
            response.contentType("text/html");
            response.send("something went wrong");
        }
        

    });

     
    
});

module.exports=empRouter;
