/* COMMENT:: task8, 0.12, 07-12-20 22:44*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int
main(int argc, char** argv) {

	int test_counter = 0;

	char* buf = (char*)malloc(1000);

	if (argc != 2)
		return -1;

	FILE* log_file = fopen(argv[1], "r");

	if (!log_file)
		return -1;
	
	char* go = 0;
	while(1) { 
		go = fgets(buf, 1000, log_file);
		if (!go) {
			printf("%d of 3\n", test_counter);
			return 0;
		}
			
		char* pass = strstr(buf, "PASS");
		if (pass)
			test_counter++;

		free(buf);
		buf = (char*)malloc(1000);

	}
}
