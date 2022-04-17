// Name: Andrew Shiraki
// Date: 2022-03-19
// Title: Lab3 – task1
// Description: This program emulates the shell command:  ls | more 
// 

#include <sys/types.h>
#include <sys/ipc.h>

/*Sample C program for Lab assignment 3*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//main
int main() {
	int fds[2];
	pipe(fds);
	/*child 1 duplicates downstream into stdin */
	if (fork() == 0) {
		//dup2 copies the stdin file descriptor to the pipe and closes original (instead of print to stdin it sends to the pipe)
		dup2(fds[0], 0);
		close(fds[1]);
		execlp("more", "more", NULL);
	}
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
		//dup2 closes stdout and copies it's fd to pipe (instead of printing to console, ls will send output to the pipe)
		dup2(fds[1], 1);
		close(fds[0]);
		execlp("ls", "ls", NULL);
	}

	else { /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0);
	}
	return 0;
}
