var maths = require('./maths.js');
var print = require('./utils.js');

if(require.main === module)
{
    print('Hello World');
    print(maths.add(maths.pi, 2));
}
