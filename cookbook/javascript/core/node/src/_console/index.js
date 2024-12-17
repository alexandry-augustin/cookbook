const fs = require("fs");
const { Console } = require("console");

if(require.main === module)
{
    {
        const myLogger = new Console({
            stdout: fs.createWriteStream("./out/stdout.txt"),
            stderr: fs.createWriteStream("./out/stderr.txt"),
        });
    
        myLogger.log("Standard output");
        myLogger.error("Error output");

        myLogger.log({ a: 'abc', b: 123 });
    }
}