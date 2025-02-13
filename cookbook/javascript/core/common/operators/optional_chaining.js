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
    test_optional_chaining();
}