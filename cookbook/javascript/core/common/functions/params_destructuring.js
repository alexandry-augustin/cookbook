// https://www.simonsmith.io/destructuring-objects-as-function-parameters-in-es6

// ES5
function f_00(params)
{
    let a = params.a;
    let b = params.b;
    let c = params.c === undefined ? 'default-value' : params.c;

    console.log(a, b, c);
}

// ES6
function f_01({a, b, c='default-value' } = {})
{
    // `= {}` allow is the default value of params.
    // This allows to call `f_01();` without error.
    console.log(a, b, c);
}

if(require.main === module)
{
    f_00({ a: 'abc', b: 123 });
    f_00({ a: 'abc', b: 123, c: 'actual-value' });

    f_01();
    f_01({ a: 'abc', b: 123 });
    f_01({ a: 'abc', b: 123, c: 'actual-value' });

    // console.assert(f(1, 2)==2);
}