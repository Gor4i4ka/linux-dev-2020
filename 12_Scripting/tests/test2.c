#include "buf.h"

int
main(void) {
        float* a = 0;
	int flag = 0;
        TEST("size init", buf_size(a) == 0, flag);

	return flag;
}

