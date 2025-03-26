if(require.main === module)
{
    {
        let v = Number("99");
        console.assert(typeof(v) === 'number');
        console.assert(v == 99);
    }
    {
        let v = parseInt("99", 10);
        console.assert(typeof(v) === 'number');
        console.assert(v == 99);
    }
    {
        let v = parseFloat("99.01");
        console.assert(typeof(v) === 'number');
        console.log(v);
    }
    {
        console.assert(isNaN(parseFloat("geoff")));
    }
}
