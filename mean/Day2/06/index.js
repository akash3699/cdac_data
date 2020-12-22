var http= require("http");

var myData = 
[
    {No : 11, Name: "Mahesh1", Address: "Pune1"},
    {No : 12, Name: "Mahesh2", Address: "Pune2"},
    {No : 13, Name: "Mahesh3", Address: "Pune3"}
];

var server= http.createServer(function(request, response){
    // console.log("Server is processing the request");    
    //response.write("request received for " + request.url);
    // response.write("Hello From Node Server");
    if(request.url == "/")
    {
        response.setHeader("Content-Type", "text/html");
        response.write("Welcome home");
    }
    else if(request.url == "/employees/show")
    {
        response.setHeader("Content-Type", "application/json");
        response.write(JSON.stringify(myData));
        // response.write("Displaying Employees...");
    }
    else
    {
        response.statusCode = 404;
        response.write("Nahi hai bhai..");
    }

    response.end();
});


server.on("connection",function(){
    console.log("New Request Received...");    
});

server.listen(5000);
console.log("Server Started ...");
