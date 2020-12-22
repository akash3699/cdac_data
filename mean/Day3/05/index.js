var EventEmitter= require("events");

var Logger = require("./logger");
var logger = new Logger();

logger.on("afterLog", function ()
                        {
                            console.log("Audit: Log is done!");
                        });
logger.log();
