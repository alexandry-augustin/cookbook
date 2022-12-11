#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//postfix increment has a higher precedence dereference

// ++ptr* //nok derefencing operator always on the left
// ++*ptr == ++(*ptr)
// *ptr++ == *(ptr++)
// *++ptr == *(++ptr)
// == (*ptr)++

void compact_expressions_test()
{
	{
		int a[]={ 0, 9 };
		int* ptr=a;

		//assert(++(*ptr)==1);
		//or
		assert(++*ptr==1);

		assert(ptr==a);
		assert(*ptr==1);
	}
	{
		int a[]={ 0, 9 };
		int* ptr=a;

		assert((*ptr)++==0);
		//or
		//...

		assert(ptr==a);
		assert(*ptr==1);
	}
	{
		int a[]={ 0, 9 };
		int* ptr=a;

		//assert(*ptr++==0);
		//or
		assert(*(ptr++)==0);

		assert(ptr==a+1);
		assert(*ptr==9);
	}
	{
		int a[]={ 0, 9 };
		int* ptr=a;

		//assert(*++ptr==9);
		//or
		assert(*(++ptr)==9);

		assert(ptr==a+1);
		assert(*ptr==9);
	}
}

void ptr_arithmetic()
{
	{
		//void* behave like char*
		int n=5;
		int* p_00=&n;
		void* p_01=(void*)(&n);

		assert(p_01+1==(void*)p_00+sizeof(char));
		assert(p_00+1==(void*)p_00+sizeof(int));
	}
}

void misc_test()
{
	{
		int n=0;
		int* p=&n;

		assert(&*p==p);
	}
	{
		int n=0;
		int* p=&n;

		assert(p); //<=> assert(p!=0);	
		//if(p) <=> if(p!=0)
	}
	{
		int n=0;
		int* p=&n;
		//printf("%p\n", &p);
	}
	{
		//type conversion

		int n=0;
		int* p;

		//p=n; //nok: can't convert int to int*
		p=0;
		//p=1; //nok: only the integer '0' is valid
		p=(int*)n;
		p=(void*)n;
		p=(void*)100;
	}
}

int main()
{
	compact_expressions_test();
	ptr_arithmetic();
	misc_test();

	return 0;
}
