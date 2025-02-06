function add(...args)
{
    let sum=0;
    for (let arg of args) 
        sum += arg;
    
    return sum;
}

if(require.main === module)
{
    console.assert(add(1)==1);
    console.assert(add(1, 2)==3);
}