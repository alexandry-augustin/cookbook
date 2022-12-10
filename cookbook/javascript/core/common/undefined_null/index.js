if(require.main === module)
{
    {
        console.assert((null === undefined) == false) // not the same type
        console.assert(null == undefined) // the "same value"
        console.assert(null === null) // both type and value are the same
        console.assert(undefined === undefined) // both type and value are the same
    }
}