var fs = require('fs');
const path = require('path');

var handle_error = function(err, result)
{
    if(err)
        console.error(err);
}

function ls(fullpath)
{
	const files = fs.readdirSync(fullpath);

	for(const file of files)
	{
        console.log(file);
        
        const stat = fs.lstatSync(path.join(fullpath, file));
        stat.isFile();
        stat.isDirectory();
	}
}

function sync()
{
    var data = fs.readFileSync('./data.txt', 'utf8');

    console.log(data);

    fs.writeFileSync('./out/sync.txt', data);

    fs.unlink('./out/sync.txt', handle_error) // delete the file

    fs.mkdirSync('./out/dir');

    fs.rmdirSync('./out/dir');
    
}

function async_()
{
    fs.readFile('./data.txt', 'utf8', 
            function(err, data)
            {
                console.log(data);

                fs.writeFile('./out/async.txt', data, handle_error);
            });


    fs.mkdir('./out/dir',
            function()
            {
                console.log('directory create');
            });

    // fs.rmdir('./out/dir');
    
    //fs.rename();
    
}

function stream_and_pipe()
{
   var read_stream  = fs.createReadStream(__dirname + '/data.txt', 'utf8'); 
   var write_stream = fs.createWriteStream(__dirname + '/out/out.txt'); 

    read_stream.on('data',
            function(chunk)
            {
                // console.log(chunk);
                write_stream.write(chunk);
            });

   read_stream.pipe(write_stream);
}

if(require.main === module)
{
	ls(__dirname);
    //sync();
    //async_();
    //streaming();
    //stream_and_pipe();
}
