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
	/*child 2 duplicates upstream into stdout */
	if (fork() == 0) {
		dup2(fds[1], 1);
		close(fds[0]);
		execlp("ls", "ls", NULL);
	}
	/*child 1 duplicates downstream into stdin */
	else if (fork() == 0) {
		dup2(fds[0], 0);
		close(fds[1]);
		execlp("more", "more", NULL);
	}

	else { /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0);
	}
	return 0;
}
