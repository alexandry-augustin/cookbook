function map()
{
    {
        let persons = [
          { age: 20, name: 'Alice' },
          { age: 24, name: 'Bob' },
          { age: 56, name: 'Alex' },
          { age: 88, name: 'Tom' }
        ];

        // let a = [];
        // persons.forEach(function (person) {
        //   a.push(person.name);
        // });

        let a = persons.map(function (person) {
          return person.age;
        });

        console.log(a);
    }
    {
        let persons = [
          { age: 20, name: 'Alice' },
          { age: 24, name: 'Bob' },
          { age: 56, name: 'Alex' },
          { age: 88, name: 'Tom' }
        ];

        let str = persons.map(function (person) {
            return `${person.name} has ${person.age}`;
        }).join(", ");

        console.log(str);
    }
}

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

function filter()
{
    {
        let persons = [
          { age: 20, name: 'Alice' },
          { age: 24, name: 'Bob' },
          { age: 56, name: 'Alex' },
          { age: 88, name: 'Tom' }
        ];

        let old = persons.filter(function (person) {
          return person.age > 20;
        });

        console.log(old);
    }
}

if(require.main === module)
{
    filter();
    map();
    reduce();
    // {
    //     let a = [ 0, 1, 2, 3, 4, 5 ];
    // }
    {
        let persons = [
          { age: 20, name: 'Alice', country: 'UK' },
          { age: 24, name: 'Bob', country: 'ES' },
          { age: 56, name: 'Alex', country: 'FR' },
          { age: 88, name: 'Tom', country: 'UK' }
        ];

        const total = persons
          .filter(person => person.country === 'UK')
          .map(person => person.age)
          .reduce((acc, n) => acc + n, 0);

        console.assert(total == 108);
    }
}
