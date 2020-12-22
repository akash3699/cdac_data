var logger=require("./logger");

var logger1=new logger();

logger1.on("loggedin",function(){
    console.log("Loggedin by Sample2");
});

logger1.log();