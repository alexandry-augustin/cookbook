#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "base_00.h"
#include "base_01.h"

// T* get()
// T& operator*
// t* operator->
// operator=
// T* release()
// void reset(T* p=0)

//no two std::auto_ptr objects should own the same element, since both would try 
//to destruct them at some point. When an assignment operation takes place 
//between two std::auto_ptr objects, ownership is transferred, which means that 
//the object losing ownership is reset to no longer point to the element (it 
//is set to the null pointer).

//not to be used in STL containers

void f_00() { }
//std::auto_ptr<int> f_01() { return new int; } //nok
//std::auto_ptr<int> f_02() { return std::auto_ptr<int>(6); }

int main()
{
	{
		//release
		std::auto_ptr<base> p_00(new base(5));

		assert(p_00.get()!=0);
		base* p_01=p_00.release();
		assert(p_00.get()==0);
	}
	{
		//reset
		std::auto_ptr<base> p_00(new base(5));

		assert(p_00.get()!=0);
		p_00.reset(); //calls ~base()
		assert(p_00.get()==0);

		p_00.reset(new base(3));
		assert(p_00.get()!=0); //calls ~base()
	}
	{
		//transfer of ownership
		std::auto_ptr<base> autoptr1(new base(6));
		std::auto_ptr<base> autoptr2;
		base* mc=NULL;

		autoptr2=autoptr1; //now autoptr2 owns the pointer & autoptr1 doesn't
		mc=autoptr2.get();
		assert(autoptr2.get()==mc);
		mc=autoptr2.release(); //sets internal pointer to null pointer without destructing the object pointed
		assert(autoptr2.get()==NULL);
		autoptr2.reset(); //destructs the object if any
		autoptr2.reset(new base(5)); //new initialisation of internal pointer
	}
	{
		typedef void (*f_t)();
		f_t f=f_00;
		std::auto_ptr<f_t> p_00;

	}
	{
		//Declaration
		int* ptr(new int(5)); //int* ptr=new int(5);
		std::auto_ptr<int> a_ptr2(new int(5));
		
		std::auto_ptr<int> a_ptr1(ptr);
		std::auto_ptr<int> a_ptr3(a_ptr2);
		std::auto_ptr<base> p(new base(4));

		//std::auto_ptr<int*> p(new int);//nok
		std::vector<std::auto_ptr<int> > int_vector01;
		std::vector<std::auto_ptr<int*> > int_vector02;

		//Usage
		//delete ptr;
		*a_ptr1=6;
	}
	return 0;
}
