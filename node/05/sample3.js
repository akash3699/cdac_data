var logger=require("./logger");

var logger1=new logger();

logger1.on("loggedin",function(){
    console.log("Loggedin by Sample3");
});

logger1.log();