var EventEmitter = require("events");

class Logger extends EventEmitter
{
    log()
    {
        console.log("Somthing Logged");
        this.emit("loggedin");
    }
}

module.exports=Logger;