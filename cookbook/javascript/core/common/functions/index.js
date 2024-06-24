function add_one(n)
{
    return n+1;
}

function named_properties({ lhs, rhs })
{
    return lhs + rhs;
}
//---------------------------------------------------------
// * primitive data types are passed by value
// * arrays and objects are passed by reference
// * can't pass primitive data types by reference (use global variables, class wrapper, return value))
//---------------------------------------------------------
function f_00()
{
}

function f_01(arg_00)
{
}

function f_02(arg_00)
{
	return arg_00;
}

function f_03(arg_00)
{
	arg_00=1;
}

function f_04(arg_00)
{
	function f_05(arg_00)
	{
		return arg_00;
	}	
	return f_05(arg_00);
}

if(require.main === module)
{
    {
	    console.assert(add_one(5)==6);
    }
    {
        let ret = named_properties({ lhs: 5, rhs: 3 });
        console.assert(ret === 8);
    }
    {
        // a function returns 'undefined' by default
        console.assert(f_00() == undefined);
    }
    {
        console.assert(f_01("abc") == undefined);
    }
    {
        console.assert(f_02("abc")=="abc");
        console.assert(f_02()==null);
    }
    {
        console.assert(f_02("abc")=="abc");
        let n=5;
        f_03(n);
        console.assert(n==5);
    }
    {
        console.assert(f_02("abc")=="abc");
        console.assert(f_04(5)==5);
    }
    {
        console.assert(f_02("abc")=="abc");
        //function object:
        //new Function(arg_00, arg_01, ..., "function body");
        let g_00=new Function("return 'abc';");
        console.assert(g_00()=="abc");

        //let g_01=new Function(arg_00, "return arg_00;");
        //console.assert(g_01(5)==6);
    }
    {
        console.assert(f_02("abc")=="abc");
        //lambda function:
        let g_02 = function(arg_00) { return arg_00; }
        console.assert(g_02(5)==5);
    }
    {
        console.assert(f_02("abc")=="abc");
        // arrow functions
        let g_03 = (val) => "abc " + val;
        // same as
        g_03 = function(val)
        {
            return "abc" + val;
        } 
    }

}
