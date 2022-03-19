/*Sample C program for Lab assignment 1*/ 
#include <stdio.h>      /* printf, stderr */ 
#include <sys/types.h>  /* pid_t */ 
#include <unistd.h>     /* fork */ 
#include <stdlib.h>     /* atoi */ 
#include <errno.h>      /* errno */  
#include <sys/wait.h> //for wait
/* main function with command-line arguments to pass */ 
int x;
int main(int argc, char *argv[]) { 
    if (fork()){
	   x=1;
    } else {
	   x=4;
    }
   printf("%d" ,x); 
    return 0; 
} 
