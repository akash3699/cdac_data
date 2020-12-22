
var someData = "Something";
function logger(someData)
{
    console.log("hello  "+someData);
}
// logger();

module.exports.logger=logger;
module.exports.someData=someData;
