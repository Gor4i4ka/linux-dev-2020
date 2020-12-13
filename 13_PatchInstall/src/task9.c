#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)
#define BUF_SIZE 10


int
main (void) {
	/* Setting the i18n environment */
  	setlocale (LC_ALL, "");
  	bindtextdomain ("task9", LOCALE_PATH);
  	textdomain ("task9");


	// User invitation
	printf(_("Guess a number in [1, 100] range\n"));
	fflush(stdout);

	// Necessary variables
	unsigned int left = 1;
	unsigned int right = 100;
	unsigned int calculation;
	char* answer = (char*)malloc(sizeof(char)*BUF_SIZE); 

	// The binary search cycle
	while(left != right) {
		calculation = left + (right - left)/2;

		printf(_("Is your number more than %u? (yes/no)\n"), calculation);
		fflush(stdout);
		
		// Correct fgets
		char* fgets_return = fgets(answer, BUF_SIZE, stdin);
		if (!fgets_return) {
			printf(_("Incorrect answer input\n"));
			fflush(stdout);
			return -1;
		}
		if (!strcmp(answer, _("yes\n"))) {
			left = calculation + 1;
			continue;
		}

		if (!strcmp(answer, _("no\n"))) {
			right = calculation;
			continue;
		}

		printf(_("Never reaches here\n"));
		fflush(stdout);
		return -1;


	}

	printf(_("Your number is %u\n"), left);
	fflush(stdout);
	return 0;

}
