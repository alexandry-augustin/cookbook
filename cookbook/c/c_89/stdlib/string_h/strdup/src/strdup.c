#include <assert.h>
#include <string.h>
#include <stdlib.h>

char* strdup_00(const char* s)
{
    char* ret=malloc(strlen(s)+1);
    if(ret==NULL)
	    return NULL;
    strcpy(ret, s);

    return ret;
}

int main()
{
	{
	    char* p_00="abc";
	    char* p_01=strdup(p_00);

	    assert(p_00!=p_01);
	    assert(strcmp(p_00, p_01)==0);
	}
	return 0;
}
