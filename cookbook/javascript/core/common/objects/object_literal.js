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

    // rename a key
    // https://stackoverflow.com/questions/4647817/javascript-object-rename-key
    person['firstname'] = person['name'];
    delete person['name'];
    console.log(Object.keys(person));
}
