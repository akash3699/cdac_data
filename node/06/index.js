var http = require("http");

var mydata=[{"CourseId":"1001","CourseName":"PG-DAC","Fees":"90000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1002","CourseName":"PG-DMC","Fees":"90000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1003","CourseName":"PG-DESD","Fees":"90000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1004","CourseName":"PG-DBDA","Fees":"115000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]},
{"CourseId":"1005","CourseName":"PG-DASDM","Fees":"80000","Duration":"6 months","center":[{"Name":["Sunbeam","Acts","Know It"],"city":["Karad","Pune","Pune"]}]}];

var server = http.createServer(function(request,response){
    
    if(request.url=="/")
    {
        response.setHeader("Content-Type","text/html");
        response.write("Welcome Home");
    }
    else if(request.url=="/empdata")
    {
        response.setHeader("Content-Type","application/json");
        response.write(JSON.stringify(mydata));
    }
    else
    {
        response.statusCode=404;
        response.write("Nikal pehli fursat mai ");
    }

    response.end();

});



server.on("connection",function(){
    console.log("New Request Received");
});

server.listen(35353);

console.log("Server Started");