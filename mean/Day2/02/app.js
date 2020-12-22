// var os= require("os");
 var fs= require("fs");
// var Logger =  require("./X");

//  var obj = new Logger();
//  obj.SayHi("MP");
//  obj.Log("Node JS training started");
 
//  console.log("Total Memory on Server " + os.totalmem());
//  console.log("Free Memory on Server " + os.freemem());
 
console.log("Start");
fs.readdir("./", CallMeAfterReadIsDome);
console.log("End");


function CallMeAfterReadIsDome(err, files)
{
    if(err)
    {
        console.log("Some ERR reading directory");
    }
    else    
    {
        console.log(files);
    }
}

// console.log("Start");
// var files = fs.readdirSync("./");
// console.log(files);
// console.log("End");






// console.log("Start")
// setTimeout(Middle, 5000);
// console.log("end")



// function Middle()
// {
//     console.log("Middle");
// }



 





