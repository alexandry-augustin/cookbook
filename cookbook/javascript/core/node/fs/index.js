const fs = require('fs');
const path = require('path');

let outdir = path.join('.', 'out');
let indir = path.join('.', 'in');

let handle_error = function(err, result)
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

function load_json(filename)
{

}

function save_json(filename)
{

}

function read_file(filename)
{
    let data = fs.readFileSync(filename, 'utf8');

    return data
}

function read_file_async(path, callback)
{
    fs.readFile(path, 'utf8', callback);
}

function write_file(filename, data)
{
    fs.writeFileSync(filename, data);
}

function delete_file(path)
{
    fs.unlink(path, handle_error);
}

function mkdir(path)
{
    if(fs.existsSync(path))
        return;
    
    fs.mkdirSync(path, { recursive: true });
}

function rmdir(path)
{
    if(!fs.existsSync(path))
        return;

    fs.rmdirSync(path);
}

function stream_and_pipe()
{
   let read_stream  = fs.createReadStream(__dirname + '/data.txt', 'utf8'); 
   let write_stream = fs.createWriteStream(__dirname + '/out/out.txt'); 

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
    {
	    ls(__dirname);
    }
    {
        let data = read_file(path.join(indir, 'lorem_ipsum.txt'));
        mkdir(outdir);
        let filename = 'sync.txt';
        let filepath = path.join(outdir, filename);
        write_file(filepath, data);
        delete_file(filepath);
        rmdir(outdir);
    }
    {
        // mkdir(outdir);
        // let filename = 'lorem_ipsum.txt';
        // let filepath = path.join(outdir, filename);
        
        // let callback = function(err, data)
        // {
        //     console.log(data);
    
        //     // fs.writeFile('./out/async.txt', data, handle_error);
        // }
        // read_file_async(filepath, callback);
    

        
        // fs.mkdir('./out/dir',
        //         function()
        //         {
        //             console.log('directory create');
        //         });
    
        // fs.rmdir('./out/dir');
        
        //fs.rename();
        
    }
    {
        // stream_and_pipe();
    }
}
