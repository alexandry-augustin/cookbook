function add(a, b)
{
    return a + b;
}

function rest_params(a, b, ...args)
{
    return args;
};

function destructure(...[x, y, z])
{
    return x + y + z;
};

function test_ternary()
{
    console.assert(5>6?'correct':'incorrect' === 'incorrect');
}

function test_optional_chaining()
{
    // The optional chaining (?.) operator accesses an object's property or calls a function. 
    // If the object is undefined or null, it returns undefined instead of throwing an error.

    let user = {
        "name": "alice", 
        "address": {
            "street": "5th Avenue"
        }
    };

    console.assert(user.address?.street === "5th Avenue");
    console.assert(user.pet?.cat === undefined);
    // console.log(user.pet.cat); // would throw an error
}

if(require.main === module)
{
    {
        let x = 0;

        // console.log(`${++x}`);
        // console.log(`${x}`);
        // console.log(`${x++}`);
        // console.log(`${x}`);
    }
    {
        // rest parameters

        let ret = rest_params(0, 1, 2, 3, 4);
        console.assert(ret.length == 3);
        console.assert(ret[0] == 2);
        console.assert(ret[1] == 3);
        console.assert(ret[2] == 4);
    }
    {
        // spread

        var a = [ 1, 2 ];
        console.assert(add(...a) == 3);
    }
    {
        console.assert(destructure(1, 2, 3) == 6);
    }
    
    test_ternary();
    test_optional_chaining();
}
