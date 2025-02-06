// This is now part of the language since ES6:
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Default_parameters

function f(a, b=1)
{
    return b;
}

if(require.main === module)
{
    console.assert(f(1)==1);
    console.assert(f(1, 2)==2);
}