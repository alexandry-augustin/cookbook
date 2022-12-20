const path = require('path');

if(require.main === module)
{
    const filename = path.join('home', 'alex', 'sandbox.md');
    const name = path.parse(filename).name;
    const ext = path.parse(filename).ext;
    const base = path.parse(filename).base;

    console.log(filename);
    console.log(base);
    console.log(name);
    console.log(ext);
}
