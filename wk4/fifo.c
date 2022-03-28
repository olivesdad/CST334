#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
int main ( int argc, char *argv[]){
	char buff[12];
	int request, temp, cacheSize;
	bool hit;
	int numPages=0;
	int numFaults=0;
	//make sure a cache size is specified
	if (argc != 2 || atoi(argv[1]) < 1) {
		printf("requires integer for cache size"); 
		return 1;
	}
	cacheSize=atoi(argv[1]);
	int *cache;
	cache = (int *) calloc( cacheSize, sizeof(int));

	//read line ints into buffer
	temp = 0;
	while (fgets(buff, 12, stdin ) != NULL){
	//this is the current page request
		request = atoi(buff);
		numPages++;
	
		//check if request is in cache
		hit=false;
		for (int i = 0; i < cacheSize; i++){
			if (cache[i] == request){
			//	printf("hit on %d \n", request);
				hit=true;
				break;
			}
		}
		//if we didnt hit we need to shift everything up and pop the last value
		if (!hit){
			for (int i = cacheSize - 2; i >= 0; i--){
				cache[i+1] = cache[i]; 
			}
			cache[0] = request;
			printf("%d not found in cache \n", request);
			numFaults++;
		} 		
	}	

	//print totals 
	printf("Number of pages read: %d\n", numPages);
	printf("Cache size: %d\n", cacheSize);
	printf("Number of Faults: %d\n", numFaults);

	//release memory
	free(cache);
	return 0;
}

