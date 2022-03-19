#include <stdio.h>

/* #define DEBUG */
main() {
#ifdef DEBUG
   printf("Debug flag on\n");
#endif
   printf("Hello world\n");
}
