#include <iostream>
#include <string>

class base
{
public:
	base() { std::cout<<"Constructor: base"<<std::endl; }
	virtual void print(){std::cout<<"base.print()"<<std::endl;}
	virtual ~base() { std::cout<<"Destructor: base"<<std::endl; }

	int b;
};

class sub: public base
{
public:
	sub(){	std::cout<<"Constructor: sub"<<std::endl;	}
	void print(){std::cout<<"sub.print()"<<std::endl; }
	~sub() { std::cout<<"Destructor: sub"<<std::endl;	}

	int s;
};

class subsub: public sub
{
public:
	subsub() { std::cout<<"Constructor: subsub"<<std::endl; }
	void print(){ std::cout<<"subsub.print()"<<std::endl; }
	~subsub() {	std::cout<<"Destructor: subsub"<<std::endl; }

	int ss;
};

class base_00
{
	virtual void f()=0;
};
void base_00::f()
{
    //implementation
}

int main(int argc, char* argv[])
{
	{
		base* b_=new subsub();
		std::cout<<b_->b<<std::endl;
		delete b_;
	}
	{
		base* basePtr[3];

		base b;
		sub s;
		subsub ss;
		
		basePtr[0]=&b; basePtr[1]=&s; basePtr[2]=&ss;
		for(int i=0; i<3;++i)
			basePtr[i]->print();
		
		sub* subPtr[2];
		
		subPtr[0]=&s; subPtr[1]=&ss;
		for(int i=0; i<2;++i)
			subPtr[i]->print();
	}
	{
		//base_00 b;
	}
    
	return 0;
}
