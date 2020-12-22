
var someData = "Something hard coded in X";

function SayHi(message)
{
    //window.alert("Hello " + message);
    console.log("Hello " + message);
}

module.exports.SayHi = SayHi;
module.exports.someData = someData;