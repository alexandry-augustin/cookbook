if(require.main === module)
{
    {
        const A = new Set([ 1, 2, 2 ]);
        A.add(3);
        console.log(A);
        console.log(A.size)

        A.delete(2);
        console.log(A);

        console.log(A.has(1));

        A.clear();
        console.log(A);

        // entries() Returns an Iterator with the [value,value] pairs from a Set
        // forEach() Invokes a callback for each element
        // keys()    Same as values()
        // values()  Returns an Iterator with the values in a Set
    }
    {
        const A = new Set([ 1, 2, 2, 3 ]);
        const B = new Set([ 1, 2, 4 ]);

        console.log(A.difference(B));
    }
}