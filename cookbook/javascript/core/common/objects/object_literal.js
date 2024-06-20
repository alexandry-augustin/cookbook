// object literal

let assert = require('assert');

if(require.main === module)
{
    let person = {
        name: 'alex',
        exist: true
    };

    assert(person.name === person['name']);

    person.name = 'rob';
    assert(person.name === 'rob');
    person['exist'] = false;
    assert(person.exist === false);

    const keys = Object.keys(person);
    const values = Object.values(person);

    console.log(keys);
    console.log(values);
}
