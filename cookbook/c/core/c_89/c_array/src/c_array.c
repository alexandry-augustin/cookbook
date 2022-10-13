#include <assert.h>
#include <stdio.h>

void f_00(int a[10], int b[], int* c)
{
	assert(sizeof(a)==4);
	assert(sizeof(b)==4);
	assert(sizeof(c)==4);
}

void f_01(int** a)
{
}
void f_02(int a[2][2])
{
}
void f_03(int a[][2])
{
}
//void f_04(int a[][]) { } //nok

int main()
{
	{
		int a[3]; //no need to allocate memory
		a[0]=1;
	}
	{
		int a[0];
		assert(!a);
	}
	{
		int a[]={1, 1, 1};
		//or
		//int a[3]={1, 1, 1};
		int* p=a;

		//a=p; //nok
	}
	{
		int a[3]={1, 1, 1};

		assert(a==&a[0]);
		//&a
	}
	{
		int a[3]={1, 1, 1};

		assert(a[0]==1);
		assert(a[1]==1);
		assert(a[2]==1);
	}
	{
		int a[3][3]={{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
		int b[3][3]={1, 1, 1, 1, 1, 1, 1, 1, 1};
		int c[][3]={{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

/*		int i, j;
		for(i=0; i<3; ++i)
			for(j=0; j<3; ++j)
				b[i][j]=1;*/
	}
	{
		int a[10];
		f_00(a, a, a);
	}
	{
		//pointer arithmetic
		int a[10];
		int* ptr=a;
		int i=2;

		//assert(&(ptr+i)==a+(sizeof(int)*i));

		//a=a+1; //nok
		ptr=a+1;
	}
	{
//		int a[10][12]; //type(a)!=int**; a[][] is continguous in memory
//		int* a[10]; //type(a)==int**
	}
	{
		int* p_00=NULL;
		int* p_01=NULL;
		p_00+=1;
		assert((p_00-p_01)==1); //must be of same type (int*)
	}
	return 0;
}
