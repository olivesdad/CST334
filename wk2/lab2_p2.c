/*Sample C program for Lab assignment 1*/ 
#include <stdio.h>      /* printf, stderr */ 
#include <sys/types.h>  /* pid_t */ 
#include <unistd.h>     /* fork */ 
#include <stdlib.h>     /* atoi */ 
#include <errno.h>      /* errno */  
#include <sys/wait.h> //for wait
/* main function with command-line arguments to pass */ 
int main(int argc, char *argv[]) { 
    pid_t  pid; 
    
    pid = fork(); 
    if (pid == -1) { 
        fprintf(stderr, "can't fork, error %d\n", errno); 
    }     
    if (pid){ 
        // Parent process 
	wait(NULL);
	printf("%s\n", "Child Complete!"); 
    } 
    else{ 
        // Child process 
	execlp("/bin/ls", "ls",NULL);
        exit(0); 	
    	} 
    return 0; 
} 
