#include <assert.h>
#include <string.h>
#include <stdlib.h>

char* strcat(char* /*restrict*/ s1, const char* /*restrict*/ s2)
{
	char* s=s1;
	/* Move s so that it points to the end of s1.  */
	while(*s!='\0')
		s++;
	/* Copy the contents of s2 into the space at the end of s1.  */
	strcpy(s, s2);

	return s1;
}

int main()
{
	{
	}
	return 0;
}
