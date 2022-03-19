#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	char letterA='a';
	int intA='a';

	printf("%x %d, %x %d\n", letterA, sizeof(letterA), intA, sizeof(intA));
	printf("%c %c\n",letterA, intA);
	exit(0);
}
