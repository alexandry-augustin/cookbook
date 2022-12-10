#include <cassert>
#include <cstdio>
#include <vector>
#include <iostream>

class A
{
	int* m_a;
public:
	A(int a):
		m_a(new int(a))
	{ 
	}
	~A()
	{
		/*delete m_a;*/ /*!!!*/
	}
	int* getA()
	{
		return m_a;
	}
};

class base
{
	int* n;
public:
	base(): n(NULL) {}

	int* getN() const
	{
		return n;
	}
};

int main() 
{
	{
		int* ptr=new int(5);
		*ptr+=1;
		assert(*ptr==6);
	}
	{
		int* ptr=0;
		assert(ptr==0);
		assert(ptr==NULL);
	
		ptr=NULL;
		assert(ptr==0);
		assert(ptr==NULL);
	
		std::cout<<ptr<<std::endl;
	}
	{
		A* a=new A(9);
		int* b=a->getA();
		delete a;
		std::cout<<(*b)<<std::endl;
		delete b; //!!!
	}
//--- Pointer deletion
	{
		A* u=new A(9);

		if(u!=NULL)  //useless, delete already do the check
		delete u;	//delete doesn't set prt to NULL
		u=NULL;
	}
//--- Dangling pointer
//pinters that do not point to a valid object of the appropriate type
	{
		int* dp=NULL;
		{
			int c=8;
			dp=&c;
			std::cout<<"::"<<*dp<<std::endl;
		} 
		//std::cout<<"::"<<*dp<<std::endl; //c falls out of scope, dp is now a dangling pointer
	}
//--- Pointer to array
	{
		int size=4;
		int* a2=new int[size];
		a2[0]=0; a2[1]=1; a2[2]=2; 
		std::cout<<a2[0]<<a2[1]<<a2[2]<<std::endl;
		delete[] a2;
	}
//--- Pointer to Pointer
	{
		int i = 5;
		int j = 6; 
		int k = 7;
		
		int* ip1 = &i;
		int* ip2 = &j;
		int** ipp = &ip1;
		*ipp = ip2;
		*ipp = &k;
	}
//--- Pointer to Vector
	{
		std::vector<int> v(5, 6), w(2,2);
		std::vector<int>* pv=&v;
		std::cout<<pv->at(0)<<std::endl;
		pv=&w;
		std::cout<<pv->at(1)<<std::endl;
		pv->at(0)=5;
		std::cout<<pv->at(0)<<std::endl;
		std::cout<<w[0]<<std::endl;
	}
	{
		base b_;
		assert(b_.getN()==NULL);
		int* n=b_.getN();
		assert(n==NULL);
		n=new int(9);
		assert(n!=NULL);
		assert(b_.getN()!=NULL); //failed
		std::cout<<*(b_.getN())<<std::endl;
	}
	return 0;
}
