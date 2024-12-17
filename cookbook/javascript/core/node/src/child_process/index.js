const { exec, spawn } = require("child_process");

function exec_test()
{
	exec("ls -la", 
		(error, stdout, stderr) => 
		{
			if(error) 
			{
				console.log(`error: ${error.message}`);
				return;
			}
			if(stderr)
			{
				console.log(`stderr: ${stderr}`);
				return;
			}
			console.log(`stdout: ${stdout}`);
		});
}

function spawn_test()
{
    // spawn(): executes a command in a new process

    const ls = spawn("ls", ["-la"]);
}

function event_listeners_test()
{
    ls.stdout.on("data", data => {
        console.log(`stdout: ${data}`);
    });
    
    ls.stderr.on("data", data => {
        console.log(`stderr: ${data}`);
    });

    ls.on('error', (error) => {
        console.log(`error: ${error.message}`);
    });

    ls.on("close", code => {
        console.log(`child process exited with code ${code}`);
    });
}

if(require.main == module)
{
    exec_test();
    spawn_test();
    // event_listeners_test();
}
