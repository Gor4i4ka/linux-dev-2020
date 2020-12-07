#include "buf.h"

int
main(void) {
        float* a = 0;
	int flag = 0;
	buf_push(a, 1.3f);
        TEST("size 1", buf_size(a) == 1, flag);

	return flag;
}

