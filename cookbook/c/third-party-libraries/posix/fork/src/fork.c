#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid */
#include <stdio.h>     /* printf, perror */
#include <stdlib.h>    /* exit */
#include <unistd.h>    /* _exit, fork */
//---------------------------------------------------------
//Fork is the primary (and historically, only) method of process creation on Unix-like operating systems.
//Immediately after the fork, the parent and the child are identical for both the code, the data and the context.
//They can modify everything in their environment independently because their contexts are separate.
//Since the code segment is identical, they will also run the same instructions just after the fork.
//Looking at the return value of the forking function is the only way to distinguish who's who.
//The parent is returned the Process ID of the child, whereas the child always gets the value "0".
//nothing is said about which between the parent or the child executes first right after fork() returns
//If a process terminates before any of its children, the process with PID 1 (init(8)) receives the paternity of them.
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	pid_t pid;
	pid_t parent_pid;
	pid_t child_pid;
	
	parent_pid=getpid();
	printf("parent pid: %d\n", parent_pid);
	pid=fork();
	if(pid==-1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else
		if(pid==0)
		{
			//child process
			child_pid=getpid();
			printf("child pid: %d\n", child_pid);
			_exit(EXIT_FAILURE);  /* exit() is unreliable here, so _exit must be used */
		}
		else //pid=pid of the child
		{
			//parent process
			int exit_status;
			(void)waitpid(pid, &exit_status, 0);
			printf("child (pid %d) exit status: %d\n", pid, exit_status);
		}
	exit(EXIT_SUCCESS);
}
