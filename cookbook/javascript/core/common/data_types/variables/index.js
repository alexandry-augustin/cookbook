//https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Values,_variables,_and_literals

// because of weak typing, there is only 1 way to declare variable: var
// basic data type: string, number (integer or float), bool

//function assert(condition, message) {
//    if(!condition) {
//        throw message || "Assertion failed";
//    }
//}

// var: defines a global variable
// let: defines a local variable

function assert(condition)
{
	if(!condition)
		console.error("assertion false");
}

if(require.main === module)
{
    {
        //weak typing
        var z;
        assert(z==undefined);
        assert(!z); //undefined value behaves as false when used in a boolean context
        z=5;
        z=9.4;
        z="abc";
        z=true;
        console.log(typeof z);
        //-------------------------------------------------
        //property dynamically added
        var c=new Object();
        c.var_00="";
        c.var_01=9;
        c.var_02=function f() { console.log("ok"); };
        c.var_02();
        //-------------------------------------------------
        var a_01= [0, 1, 2];
        assert(a_01[0]==0);
        //-------------------------------------------------
        var a=2, b=5, c;
        c=a+b;
        assert(c==7);
    }
    {
    }
    {
        let n = 5;
    }
    {
        const pi = 3.14
    }
}
