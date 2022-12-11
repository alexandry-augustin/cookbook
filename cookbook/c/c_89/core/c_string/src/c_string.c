#include <assert.h>
#include <stdio.h>

// http://stackoverflow.com/questions/8040284/why-is-literal-string-assignment-in-c-not-possible-for-array-with-specified-leng

// \\	Literal backslash
// \"	Double quote
// \'	Single quote
// \n	Newline (line feed)
// \r	Carriage return
// \b	Backspace
// \t	Horizontal tab
// \f	Form feed
// \a	Alert (bell)
// \v	Vertical tab
// \?	Question mark (used to escape trigraphs)
// \nnn	Character with octal value nnn
// \xhh	Character with hexadecimal value hh

int main()
{
	{
		char* str=NULL;

		str="abc";
		assert(strcmp(str, "abc")==0);
		str="12345";
		assert(strcmp(str, "12345")==0);
		str="1";
		assert(strcmp(str, "1")==0);
	}
	{
		char c='a';

		assert(c); // <=> assert(c!='\0' && c!=0)
		//if(c) <=> id(c!='\0' && c!=0)
	}
	{
		char a_00[]={'a', 'b', 'c', '\0'};
		char a_01[4]="abc";
		char a_02[]="abc";
	}
	{
		char *p;
		p="abc"; //string literal

		assert(p[0]=='a');
		assert(p[1]=='b');
		assert(p[2]=='c');
	}
	return 0;
}
