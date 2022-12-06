if(require.main === module)
{
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
