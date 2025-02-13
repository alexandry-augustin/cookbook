function test_ternary()
{
    console.assert(5>6?'correct':'incorrect' === 'incorrect');
}

if(require.main === module)
{
    test_ternary();
}