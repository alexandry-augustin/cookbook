
function getIntersection(set1, set2) { 
    // https://www.geeksforgeeks.org/how-to-perform-intersection-of-two-sets-in-javascript/
    const ans = new Set(); 
    for (let i of set2) { 
        if (set1.has(i)) { 
            ans.add(i); 
        } 
    } 
    return ans; 
}

function getIntersection2(set1, set2) { 
    // https://www.geeksforgeeks.org/how-to-perform-intersection-of-two-sets-in-javascript/
    return new Set([...set1].filter(x => set2.has(x)));
}

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

        // console.log(A.prototype.difference(B));
        // console.log(A.prototype.intersection(B));
        console.assert(getIntersection2(A, B).size == 2);
    }
}