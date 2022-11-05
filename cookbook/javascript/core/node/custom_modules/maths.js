var add = function(a, b)
{
    return a+b;
}

var pi = 3.14;

// module.exports.add = add;
// module.exports.pi  = pi;

// or

module.exports = { 
    add: add,
    pi: pi
}
