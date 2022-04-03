#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *go(void *);
//Matrix Dimension
#define N 2
#define M 3
#define L 3

pthread_t threads[N];
int A [N][M];
int B [M][L];
int C [N][L];



int main() {

	int i,j; //iterators
	//#######POPULATE A & B #########
	srand(time(NULL));
	for (i = 0; i < N; i++)
		for ( j = 0; j < M; j++)
			A[i][j] = rand()%10;
	sleep(1); // this prevents the random seed from being the same
	srand(time(NULL));
	for (i = 0; i < M; i++)
		for ( j = 0; j < M; j++)
			B[i][j] = rand()%10;

//We need as many threads as we have rows in A
	for (i = 0; i < N; i++){ 
		//allocate an integer to pass to new thread indicating which row to operate on
		int *arg = malloc(sizeof(int));
		*arg = i;
		printf("made thread \n");
		pthread_create(&threads[i], NULL, go, arg);
	}

	for (i = 0; i < N; i++) {//wait for all threads
		//use pthread_join for each thread in threads array
		if (pthread_join(threads[i],NULL) != 0) 
			printf("thread join failed");
		else 
		printf("Thread %d returned\n", i);
	}
	//~~~~~~~~PRINT OUT MATRIX A~~~~~~~~~~//
	printf("--------MATRIX A---------\n");
	for (i = 0 ;i < N; i++){ 
		for (j = 0; j < M ; j++)
		{
			printf(" %d ", A[i][j]);
		}
		printf("\n");
	}
		//~~~~~~~~PRINT OUT MATRIX B~~~~~~~~~~//
	printf("--------MATRIX B---------\n");
	for (i = 0 ;i < M; i++){ 
		for (j = 0; j < L ; j++)
		{
			printf(" %d ", B[i][j]);
		}
		printf("\n");
	}
	//~~~~~~~~PRINT OUT MATRIX C~~~~~~~~~~//
	printf("--------MATRIX C---------\n");
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

//num is the row we will operate on
int num = *((int*)arg);
printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), num);

//Loop for operation
int i,j;
int sum = 0;

for (i=0; i < L ; i++){ //loop through columns in B
	for (j = 0; j < M ; j++){ //iterate through each element in A row [num] * each element in B[i][j]
		sum = sum + (A[num][j] * B[j][i]);
	}

	//update matrix C Then reset sum
	C[num][i]=sum;
	sum = 0;
}
free(arg); //free allocated memory
return 0; 
}
