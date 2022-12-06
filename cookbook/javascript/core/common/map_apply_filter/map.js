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

if(require.main === module)
{
    map();
}