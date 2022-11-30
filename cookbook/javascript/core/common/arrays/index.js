// Arrays

function sort_me_out()
{
	var a = new Array();
	// or
	var a = [];

	var a = new Array(3); // array of 3 undefined elements

	var a = ["abc", 123, "def"];

	var a = new Array("abc", 123, "def");

	a[0] = "opn"

	console.assert(a[0] == "opn");

	a.sort()
	
	for(i = 0; i < a.length; i++)
	{
		a[i];
	}

	a.push(0) // insert new element

	Array.isArray(a);
	//or
	a instanceof Array;
}

function print(a)
{
    for(e in a)
        console.log(' ' + e);

    console.log(a.join('|'));
}

if(require.main === module)
{
    let a = [ 1, 'b' ];

    a[0] = 5;
    a[5] = 'alex';

    // console.log(a);
    console.assert(a.length==6);

    let b=new Array();
    //if(!myArray[0])
    //	myFunction();

    // print(a);
    
    {
        const a = [ "Banana", "Orange", "Apple", "Mango" ];
        console.assert(a.includes("Mango"));
    }
    sort_me_out();
}
