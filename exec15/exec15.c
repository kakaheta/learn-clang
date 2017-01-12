#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = {24, 32, 44, 12, 89};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way indexing
	for (i = count-1; i >= 0; i--) {
		printf("%s is %d yes alive.\n", names[i], ages[i]);
	}

	printf("----\n");

	// set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for (i = count-1; i >= 0; i--) {
		printf("%s is %d yes alive.\n", *(cur_name + i), *(cur_age + i));
	}

	printf("----\n");

	// third way are just arrays
	for (i = count-1; i >= 0; i--) {
		printf("%s is %d yes old again.\n", cur_name[i], cur_age[i]);
	}

	printf("----\n");

	// fourth way with pointers in a stupid complex way
	for (cur_name = names+count-1, cur_age = ages+count-1; (cur_age - ages) >= count; cur_name--, cur_age--) {
		printf("%s is %d yes old so far.\n", *cur_name, *cur_age);
	}

	return 0;
}