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
    {
        let persons = [
            { age: 20, name: 'Alice' },
            { age: 24, name: 'Bob' },
            { age: 56, name: 'Alex' },
            { age: 88, name: 'Tom' }
          ];
        let ages = [ 24, 88 ];
        let filtered_persons = persons.filter((person) => {
          return ages.indexOf(person.age) > -1;
        });

        console.log(filtered_persons);
    }
}

if(require.main === module)
{
    filter();
}