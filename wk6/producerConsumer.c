
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define numChars 26
char alphabet[numChars];
sem_t empty;
sem_t full;
sem_t mutex;

char *buff;
pthread_t threads[2];

void *producer(void *arg){
    int i;
    for (i=0; i < numChars; i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        *buff = alphabet[i];
        printf("(P) Wrote letter: %c\n", alphabet[i]);
        sem_post(&mutex);
        sem_post(&full);
    }
    return 0;
}

void *consumer(void *arg){
    int i;
    for (i=0; i < numChars; i++){
        
        sem_wait(&full);
        sem_wait(&mutex);
        printf("(C) Read letter: %c\n", *buff);
        sem_post(&mutex);
        sem_post(&empty);
        
    }
    return 0;
}

int main(){
    //initialize things
    buff = (char*) malloc(sizeof(char));
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    //populate the alphabet array
    int i;
    char c = 'a';
    for (i=0; i < numChars; i++){
        alphabet[i] = c + i;
    }
    //dummy buffer just incase
    *buff = '0';
    //make producer thread
    pthread_create(&threads[0], NULL, producer, NULL);
    
    //make consumer thread
    pthread_create(&threads[1], NULL, consumer, NULL);


    //wait
    if (pthread_join(threads[0],NULL) != 0) printf("failed to join producer\n");
    else printf("Producer thread ended\n");
    if (pthread_join(threads[1],NULL) != 0) printf("failed to join consumer");
    else printf("Consumer thread ended\n");
    //clean up
    free(buff);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    printf("Main done\n");
    return 0;
}