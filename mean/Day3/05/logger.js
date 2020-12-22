var EventEmitter= require("events");

class Logger extends EventEmitter
{
   log()
    {
        console.log("Something Logged");
        this.emit("afterLog");            
    }

}
module.exports = Logger;



