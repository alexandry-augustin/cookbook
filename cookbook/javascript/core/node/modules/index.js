var maths = require('./modules/maths.js');
var print = require('./modules/utils.js');

if(require.main === module)
{
    print('Hello World');
    print(maths.add(maths.pi, 2));
}
