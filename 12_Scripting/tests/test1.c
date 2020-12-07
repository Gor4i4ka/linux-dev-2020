#include "buf.h"

int
main(void) {
	float* a = 0;
	int flag = 0;
	TEST("capacity init", buf_capacity(a) == 0, flag);
	
	return flag;
}
