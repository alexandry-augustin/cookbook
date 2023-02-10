var f = function()
{
  // do something
}; 

if(require.main === module)
{
    // let dict = new Object();
    // or
	let dict = { first:"abc",
                 "second":123,
                 1: "number",
                 fct: f
               };

    dict["one"] = 1;
    dict[1] = "one";
    dict["age"] = 18;
    dict.first = "alex";

	// console.log(dict);

    for(var key in dict)
    {
      var value = dict[key];

      // do something
    }

    Object.entries(dict).forEach(([k,v]) => {
       // console.log(k, v);
    });

    let keys = Object.entries(dict).map(([k,v]) => k);
    let values = Object.entries(dict).map(([k,v]) => v);

    console.log(keys, values); 
}
