const { exec, spawn } = require("child_process");

if(require.main == module)
{
    // exec()

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

    // spawn(): executes a command in a new process

    const ls = spawn("ls", ["-la"]);

    // event listeners
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
