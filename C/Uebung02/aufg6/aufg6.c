#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include "my_strcasecmp.h"
#include "my_index.h"
#include "my_rindex.h"

void test_strcasecmp()
{
	char s1[] = "Hallo hallo";
	char s2[] = "hAlLo HaLlO";
	char s3[] = "hallo hello";

	printf("s1, s2: %d\n", strcasecmp(s1, s2));
	assert(strcasecmp(s1, s2) == my_strcasecmp(s1, s2));
	printf("s1, s3: %d\n", strcasecmp(s1, s3));
	assert(strcasecmp(s1, s3) == my_strcasecmp(s1, s3));
	printf("s2, s3: %d\n", strcasecmp(s2, s3));
	assert(strcasecmp(s2, s3) == my_strcasecmp(s2, s3));
	printf("A, DEF: %d\n", strcasecmp("A", "DEF"));
	assert(strcasecmp("A", "DEF") == my_strcasecmp("A", "DEF"));
	printf("DEF, A: %d\n", strcasecmp("DEF", "A"));
	assert(strcasecmp("DEF", "A") == my_strcasecmp("DEF", "A"));
}

void test_index()
{
	char s1[] = "Hallo a";
	char s2[] = "Hallo l";
	char s3[] = "Hallali a";
	char s4[] = "hallo e";

	printf("%c\n", *my_index(s1, 'a'));
	assert(index(s1, 'a') == my_index(s1, 'a'));

	printf("%c\n", *my_index(s2, 'a'));
	assert(index(s2, 'a') == my_index(s2, 'a'));

	printf("%c\n", *my_index(s3, 'a'));
	assert(index(s3, 'a') == my_index(s3, 'a'));

	printf("%c\n", *my_index(s4, 'a'));
	assert(index(s4, 'a') == my_index(s4, 'a'));
	assert(!my_index(s4, 'x'));

	printf("%c\n", *my_rindex(s1, 'a'));
	assert(*rindex(s1, 'a') == *my_rindex(s1, 'a'));
	
	printf("%c\n", *my_rindex(s2, 'a'));
	assert(*rindex(s2, 'a') == *my_rindex(s2, 'a'));
	
	printf("%c\n", *my_rindex(s3, 'a'));
	assert(*rindex(s3, 'a') == *my_rindex(s3, 'a'));
	
	printf("%c\n", *my_rindex(s1, 'a'));
	assert(*rindex(s4, 'a') == *my_rindex(s4, 'a'));
	assert(!my_rindex(s1, 'x'));
}

int main(void)
{
	test_strcasecmp();
	test_index();
	return 0;
}

