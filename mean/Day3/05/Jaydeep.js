var Logger = require("./logger");
var logger = new Logger();

logger.on("afterLog", function ()
                        {
                            console.log("Inserting some audit entry in DB...");
                        });
logger.log();
