

function  ValidateEmpty(element,errspan,ErrMsg)
{
    // var isItEmpty = true;
    // var element = 
    //     document.getElementById(CtrlID);
    // var element= $("#CtrlID");
    // var errspan = 
    //     document.getElementById(SpanID);
    // var errspan = $("#SpanID");
    if(element.val() == "")
    {
          errspan.html(ErrMsg);  
          isItEmpty = true;
    }
    else
    {
        errspan.html("");  
        isItEmpty = false;
    }
    return isItEmpty;
}
function ValidateForTextOnly(element, errspan,ErrMsg)
{
    // var element = 
    //     var element= $("#CtrlID");
    // var element= $("#CtrlID");
    // var errspan = 
    //     document.getElementById(SpanID);
    // var errspan = $("#SpanID");
    if(isNaN(element.val()))
    {
        errspan.html("");
    }
    else{
        errspan.html(ErrMsg);
    }
}

function ValidateForNumberOnly(element, errspan,ErrMsg)
{
    var isItNumber = false;

    // var element = $("#CtrlID");
    // var errspan = $("#SpanID");

    if(isNaN(element.val()))
    {
        errspan.html(ErrMsg);
        isItNumber = false; 
    }
    else{
        errspan.html("");
        isItNumber = true   ;

    }
    return isItNumber;
}

function ValidateForRange(element, errspan,ErrMsg,Min, Max)
{
    debugger;
    // var element = $("#CtrlID");
    // var errspan = $("#SpanID");
    var actualValue =  parseInt(element.val());
    if(actualValue < Min || actualValue >Max )
    {
        errspan.html(ErrMsg);
    }
    else{
        errspan.html("");
    }
}

function ValidateForPassword(data1,data2,errpwd,ErrMsg)
{
    // var errpwd=document.getElementById(spanID);
    // var errpwd=$("#spanID");
    // var data1=document.getElementById(pwd1);
    // var data1=$("pwd1");
    // var data2=document.getElementById(pwd2);y
    // var data2=$("pwd2");
    var isPwdEmpty=ValidateEmpty(data1,errpwd,"Password is Required");
    if(isPwdEmpty==false)
    {
        if(data1.val()==data2.val()) 
        {
            errpwd.html("");
        }
        else
        {
            errpwd.html("");
            }
    }
    else{
        errpwd.html("both passwords required");
    }
}