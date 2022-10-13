#include <stdio.h>
#include <string.h>

int main()
{
	{
		#define ALEX	0
		#define BOB	1
		#define ROB	2
		
		#define COMPILED_BY ALEX
			char name[255];
		#if COMPILED_BY == ALEX
			strcpy(name, "alex");
		#elif COMPILED_BY == BOB
			strcpy(name, "bob");
		#elif COMPILED_BY == ROB
			strcpy(name, "rob");
		#elif COMPILED_BY == ROB || COMPILED_BY == ALEX
			strcpy(name, "rob or alex");
		#else
		#error //stop compilation when reached
		#endif
			printf("%s\n", name);
	}
	{
		#define mkstr(s) #s
			printf("%s\n", mkstr(test));
	}
	{
		#define concat(a, b) a##b
		//	printf("%s\n", concat(5, 6));
	}
	{
		printf("%d\n", __LINE__);
		printf("%s\n", __FILE__);
		printf("%s\n", __DATE__);
		printf("%s\n", __TIME__);
		printf("%d\n", __STDC__);
	}
	{
		#define UN	"abc"
		#define DEUX	UN "123" //auto-concatenation (the preprocessor does no such thing.
				  	//It's the C language proper that treats adjacent string literals as if they were a single string literal)
			printf("%s\n", DEUX);
	}
	{
		#include <string.h>
		#define VERSION "1.1-5"
		#define USE strcmp(VERSION, "1.1-8")
		#if $USE <= 0
			printf("version ok\n");
		#else
			printf("version nok\n");
		#endif
	}
	{
		#define PRINT(format, x) printf(#x "=%"#format"\n", x)
			PRINT(d, 5);
	}
	return 0;
}
