#include <assert.h>
#include <string.h>
#include <stdlib.h>

// return:
// 0: both strings are equal
// >0: the first character that does not match has a greater value in s1 than in s2 (ascii comparison ?)
// <0: indicates the opposite

int strcmp_00(const char *s1, const char *s2)
{
	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	while(*p1 != '\0')
	{
		if(*p2 == '\0') return  1;
		if(*p2 > *p1)   return -1;
		if(*p1 > *p2)   return  1;

		p1++;
		p2++;
	}
	if (*p2 != '\0') return -1;

	return 0;
}

int main()
{
	{
		const char * const p_00="abc";
		const char * const p_01="2001";
		const char * const p_02="abc";
		const char * const p_03="1999";

		assert(strcmp(p_00, p_02)==0);
		assert(strcmp_00(p_00, p_02)==0);

		assert(strcmp(p_01, p_03)>0);
		assert(strcmp_00(p_01, p_03)>0);
	}
	return 0;
}
