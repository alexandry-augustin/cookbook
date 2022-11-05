// https://stackabuse.com/reading-and-writing-json-files-with-node-js/

'use strict';

const fs = require('fs');

if(require.main === module)
{
    let rawdata = fs.readFileSync('data.json');
    let student = JSON.parse(rawdata);
    console.log(student);
}
