function test_double_bang()
{
    // https://stackoverflow.com/questions/29312123/how-does-the-double-exclamation-work-in-javascript

    console.assert(!!false === false);
    console.assert(!!true === true);
    console.assert(!!null === false);
    console.assert(!!undefined === false);
    console.assert(!!0 === false);
    console.assert(!!0 === false);
    console.assert(!!1 === true);
    console.assert(!!-5 === true);
    console.assert(!!NaN === false);
    console.assert(!!'' === false);
    console.assert(!!'hello' === true);
}

if(require.main === module)
{
    test_double_bang();
}