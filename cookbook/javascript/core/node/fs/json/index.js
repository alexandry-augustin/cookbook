// https://stackabuse.com/reading-and-writing-json-files-with-node-js/

'use strict';

const fs = require('fs');

if(require.main === module)
{
    {
        let data_json = fs.readFileSync('./data/object.json');
        let data = JSON.parse(data_json);
        
        // console.log(data);
    }
    {
        let data_json = fs.readFileSync('./data/array.json');
        let data = JSON.parse(data_json);

        // console.log(data);

        // for(let item in data)
        // {
        //     console.log(item);
        // }
        for(let i=0; i<data.length; i++)
        {
            let item = data[i];
            console.log(item);
        }
    }
}
