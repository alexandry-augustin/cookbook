// https://stackoverflow.com/questions/46155/how-can-i-validate-an-email-address-in-javascript

const validateEmail = (email) => {
    let ret = String(email)
        .toLowerCase()
        .match(
            /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|.(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/
        );

    return ret?true:false;
};

const test = (email) => {
    console.log(email, validateEmail(email));
}

if(require.main === module)
{
    test('test@domain.com');
    test('test-123@123.asd.com');
    
    test('');
    test('   ');
    test('test@domain');
    test('test@');
    test('test.com');
    test('test@.com');
    test('test');
}