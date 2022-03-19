#include <stdio.h>
#include <stdlib.h>
#define BUF 256

extern int BSIZE;
int main(int argc, char** argv)
{
	char *p1 ="zzz";
	char *p2 = (char *) 'z';
	char *p3;
	p3 = malloc(sizeof(char));
	*p3 = 'z';
	printf("%x\n",p1);
	printf("%x %c\n",p2,p2);
	printf("%x %s\n",p3,p3);
}
