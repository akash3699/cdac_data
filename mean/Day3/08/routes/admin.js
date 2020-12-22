var express = require("express");
var adminrouter =  express();

adminrouter.get("/", function(req, res){
    res.send("All Admin");
});

adminrouter.get("/:No", function(req, res){
    res.send("Admin No " + req.params.No);
});
module.exports = adminrouter;






// router = express();

// router.get("/", function(req, res){
//     res.send("All Admin");
// });

// router.get("/:No", function(req, res){
//     res.send("Admin No " + req.params.No);
// });


// module.exports = router;
