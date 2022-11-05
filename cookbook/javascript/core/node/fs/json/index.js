// https://stackabuse.com/reading-and-writing-json-files-with-node-js/

'use strict';

const fs = require('fs');

if(require.main === module)
{
    let student_data = fs.readFileSync('data.json');
    let student = JSON.parse(student_data);
    console.log(student);
    
    let students_data = fs.readFileSync('array.json');
    let students = JSON.parse(students_data);
    // for(let e in students)
    // {
    //     console.log(e);
    // }
    for (var i = 0; i < students.length; i++)
    {
        student = students[i];
        console.log(student);
    }
}
