// Arrays

function init()
{
    {
        let a = new Array();
    }
    {
	    let a = [];
    }
    {
        let a = new Array(3); // array of 3 undefined elements
    }
    {
	    let a = ["abc", 123, "def"];
    }
    {
	    let a = new Array("abc", 123, "def");
    }
}

function range()
{
    // https://stackoverflow.com/questions/3895478/does-javascript-have-a-method-like-range-to-generate-a-range-within-the-supp
    let start = 5;
    let length = 3;
    let a = Array(length).fill(start).map((x, y) => x + y);
    // console.log(a);
}

function sort_me_out()
{
    let a = ["abc", 123, "def"];

	a[0] = "opn"

	console.assert(a[0] == "opn");
	
	for(i = 0; i < a.length; i++)
	{
		a[i];
	}

	a.push(0) // insert new element

	Array.isArray(a);
	//or
	a instanceof Array;
}

function sorting() {
    /* 
    The sort() method of Array instances sorts the elements of an 
    array in place and returns the reference to the same array, now sorted. 
    The default sort order is ascending, built upon converting the elements 
    into strings, then comparing their sequences of UTF-16 code units values.
    
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort
    */
    {
        let a = [0, 2, -1];
        
        a.sort();
        
        console.assert(a[0] == -1);
        console.assert(a[1] == 0);
        console.assert(a[2] == 2);
    }
    {
        let a = [0, 2, -1];

        let compareFunction = (a, b) => { return a - b; }
        a.sort(compareFunction);
        
        console.assert(a[0] == -1);
        console.assert(a[1] == 0);
        console.assert(a[2] == 2);
    }
    {
        let a = [0, 2, -1, "h", "b"];

        let compareFunction = (a, b) => { return a - b; }
        a.sort(compareFunction);
        
        //console.log(a);
        // console.assert(a[0] == -1);
        // console.assert(a[1] == 0);
        // console.assert(a[2] == 2);
    }
    {
        let a = ["aa", "aA", "Aa"];
        a.sort();
        
        console.assert(a[0] == 'Aa');
        console.assert(a[1] == 'aA');
        console.assert(a[2] == 'aa');
    }
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
        const a = [ 
            "Banana", 
            "Orange", 
            "Apple", 
            "Mango" 
        ];
        console.assert(a.includes("Mango"));
    }

    init();
    range();
    sorting();
    sort_me_out();
}
