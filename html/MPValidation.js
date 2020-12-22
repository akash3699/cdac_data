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

function ValidateForPassword(pwd1,pwd2,spanID,ErrMsg)
{
    var errpwd=document.getElementById(spanID);
    var data1=document.getElementById(pwd1);
    var data2=document.getElementById(pwd2);
    var isPwdEmpty=ValidateEmpty(pwd1,spanID,"Password is Required");
    if(isPwdEmpty==false)
    {
        if(data1.value==data2.value) 
        {
            errpwd.innerText="";
        }
        else
        {
            errpwd.innerText=ErrMsg;
            }
    }
    else{
        errpwd.innerText="both passwords required";
    }
}