/*
 * Name: Andrew Shiraki
 * Date: 2022-04-03
 * threadHello creates NTHREADS and prints hello from each thread. 
 * Uses malloc to allocate space to pass thread number to thread
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
//this is how many threads to make
#define NTHREADS 10
pthread_t threads[NTHREADS];
//int counter[NTHREADS];

int main() {
	int i;
	for (i = 0; i < NTHREADS; i++){// create all n threads

		//allocate space for new int and assign it value of i
		int *arg = malloc(sizeof(int));
		*arg = i;
		if (pthread_create(&threads[i], NULL, go, arg) !=0){
			//if we fail to create thread, free allocated memory and abort
			free(arg);
			printf("failed to create thread\n");
			return 1;
		}
	}
	for (i = 0; i < NTHREADS; i++) {//wait for all threads
		//use pthread_join for each thread in threads array
		if (pthread_join(threads[i],NULL) != 0) 
			printf("thread join failed");
		else 
		printf("Thread %d returned\n", i);
	}
	printf("Main thread done.\n");//say were done
	return 0;
}

//routine each thread will run
void *go(void *arg) {
//print the arg passed in
printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);

//were done with the allocated memory
free(arg);
return 0; 
}
