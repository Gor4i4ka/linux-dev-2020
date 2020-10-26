#include <stdlib.h>

void
main(void) {
	int* p1 = malloc(100000);
	free(p1);
	free(p1);
}
