/** @file
 * task9.c realizes task9*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include <libintl.h>
#include <locale.h>

/** 
 * gettext macro to perform i18n and localization
 */
#define _(STRING) gettext(STRING)
/**
 * Bufsize for yes/no answer
 */
#define BUF_SIZE 10
/**
 * Roman counting system table size
 */
#define TRANSLATION_TABLE_SIZE 100

/**
 * The global variable, which stores arabic-roman representation of numbers.
 * roman number == integer index in the array + 1
 */
static char* translation_table[TRANSLATION_TABLE_SIZE] = {
"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", 
"XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", 
"XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", 
"XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL", 
"XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", 
"LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", 
"LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX", 
"LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX", 
"LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC", 
"XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"};

/**
 * The function-getter, which stores the help message.
 * The message could be induces with --help option.
 * @return help message.
 */
char*
get_help(void) {
	char* help_message;
	if (!strcmp(getenv("LANG"), "ru_RU.utf8")) {
		setlocale(LC_ALL, "Rus");
		help_message=
"task9 --- Программа отгадывает число в сегменте [1, 100] (с поддержкой римской системы счисления)\n\
\n\
Использование: task9 [ОПЦИЯ]\n\
\n\
	--help	Напечатать это сообщение и выйти.\n\
	-r	Переключиться на римскую систему счисления\n\
";
		return help_message;
	}
	help_message = 
"task9 --- The programm to guess a number in [1,100] (roman supported)\n\
\n\
Usage: task9 [OPTION]\n\
\n\
	--help	print this message, then exit\n\
	-r	switch to roman counting system\n\
";
	return help_message;
}

/**
 * This function converts integer num in arabic system to
 * char* representation in roman counting system.
 * @param num as an integer argument.
 * @return roman representation of num.
 */
char *
convert2roman(int num) {
	return translation_table[--num];
}

/**
 * This function converts char* roman_num in roman system to
 * int representation in arabic counting system.
 * @param roman_num as char* argument.
 * @return arabic representation of roman_num.
 */
int
convert2int(char* roman_num) {
	for (unsigned int i=0; i < TRANSLATION_TABLE_SIZE; i++)
		if (!strcmp(roman_num, translation_table[i]))
			return ++i;
	return -1;
}
/**
 * This function represents the algorithm,
 * which guesses your number in [1, 100] segment
 * using binary search.
 */
int
main (int argc, char** argv) {

	// Counting system flag (0 - standard, 1 - roman)
	unsigned char c_system_ind = 0;

	if (argc >= 2) {
		if (!strcmp("-r", argv[1]))
			c_system_ind = 1;
		else
		if (!strcmp("--help", argv[1])) {
			printf("%s", get_help());
			fflush(stdout);
			return 0;
		}
		else
		if (!strcmp("--version", argv[1])) {
			printf("0.0");
			return 0;
		}
		else {
			printf(_("wrong parameter. Use --help\n"));
			fflush(stdout);
			return -1;
		}
	}

	/* Setting the i18n environment */
  	setlocale (LC_ALL, "");
  	bindtextdomain ("task9", getenv("PWD"));
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
		
		if (c_system_ind == 0)
			printf(_("Is your number more than %u? (yes/no)\n"), calculation);
		else
		if (c_system_ind == 1)
			printf(_("Is your number more than %s? (yes/no)\n"), convert2roman(calculation));
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
	if (c_system_ind == 0)
		printf(_("Your number is %u\n"), left);
	else
	if (c_system_ind == 1)
		printf(_("Your number is %s\n"), convert2roman(left));
	fflush(stdout);
	return 0;

}
