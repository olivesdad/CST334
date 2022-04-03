#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
//this is how many threads to make
#define NTHREADS 10
#define N 2
#define M 2
#define L 2
pthread_t threads[NTHREADS];
int counter[NTHREADS];
int A [N][M];
int B [M][L];
int C [N][L];



int main() {

	int i,j; //iterators
	//#######POPULATE A & B #########
	srand(time(NULL));
	for (i = 0; i < N; i++)
		for ( j = 0; j < M; j++)
			A[i][j] = rand();

	srand(time(NULL));
	for (i = 0; i < M; i++)
		for ( j = 0; j < M; j++)
			B[i][j] = rand();


	for (i = 0; i < NTHREADS; i++){
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

	//~~~~~~~~PRINT OUT MATRIX C~~~~~~~~~~//
	for (i = 0 ;i < N; i++){ 
		for (j = 0; j < L ; j++)
		{
			printf(" %d ", C[i][j]);
		}
		printf("\n");
	}
	printf("Main thread done.\n");//say were done
	return 0;
}

//routine each thread will run
void *go(void *arg) {
//argument passed is address of i in forloop which 
printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *((int*)arg));
free(arg); 
return 0; 
}
