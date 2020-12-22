function  ValidateEmpty(CtrlID,SpanID,ErrMsg)
{
    var isItEmpty = true;
    var element = 
        document.getElementById(CtrlID);
    var errspan = 
        document.getElementById(SpanID);

    if(element.value == "")
    {
          errspan.innerText = ErrMsg;  
          isItEmpty = true;
    }
    else
    {
        errspan.innerText = "";  
        isItEmpty = false;
    }
    return isItEmpty;
}
function ValidateForTextOnly(CtrlID, SpanID,ErrMsg)
{
    var element = 
        document.getElementById(CtrlID);
    var errspan = 
        document.getElementById(SpanID);

    if(isNaN(element.value))
    {
        errspan.innerText = "";
    }
    else{
        errspan.innerText = ErrMsg;
    }
}

function ValidateForNumberOnly(CtrlID, SpanID,ErrMsg)
{
    var isItNumber = false;

    var element = document.getElementById(CtrlID);
    var errspan = document.getElementById(SpanID);

    if(isNaN(element.value))
    {
        errspan.innerText = ErrMsg;
        isItNumber = false; 
    }
    else{
        errspan.innerText = "";
        isItNumber = true   ;

    }
    return isItNumber;
}
$(document).ready(function(){
    $("form").append('<a href="38KaradDemo.html"><img src="car.jpg" height="100px" width="400px"</a>');
});


function ValidateForRange(CtrlID, SpanID,ErrMsg,Min, Max)
{
    debugger;
    var element = document.getElementById(CtrlID);
    var errspan = document.getElementById(SpanID);
    var actualValue =  parseInt(element.value);
    if(actualValue < Min || actualValue >Max )
    {
        errspan.innerText = ErrMsg;
    }
    else{
        errspan.innerText = "";
    }
}
