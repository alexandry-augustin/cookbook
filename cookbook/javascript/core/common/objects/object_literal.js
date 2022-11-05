// object literal

if(require.main === module)
{
    let person = {
        name: 'alex',
        exist: true
    };

    person.name = 'rob';
    person['exist'] = false

    console.log(person);
}
