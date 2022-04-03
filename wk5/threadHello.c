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
		//Creates thread an puts threadid into threads array,
		//attribute NULL == default idk what that will be
		//it runs the process go
		// arg passed to the thread id is address of i
		//counter[i] = i;
		int *arg = malloc(sizeof(int));
		*arg = i;
		pthread_create(&threads[i], NULL, go, arg);
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
//argument passed is address of i in forloop which 
printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
free(arg);
return 0; 
}
