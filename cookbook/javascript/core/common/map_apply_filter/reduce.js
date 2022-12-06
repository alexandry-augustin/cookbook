function reduce()
{
    // generate a single value or object from an array
    
    {
        let persons = [
          { age: 20, name: 'Alice' },
          { age: 24, name: 'Bob' },
          { age: 56, name: 'Alex' },
          { age: 88, name: 'Tom' }
        ];

        let init = 0;
        let a = persons.reduce(function (accumulator, person) {
          return accumulator + person.age;
        }, init);

        console.assert(a == 20+24+56+88);

        var oldest = persons.reduce(function (acc, person) {
          return (acc.age || 0) > person.age ? acc : person;
        }, {});

        console.log(oldest.name);
    }
}

if(require.main === module)
{
    reduce();
}