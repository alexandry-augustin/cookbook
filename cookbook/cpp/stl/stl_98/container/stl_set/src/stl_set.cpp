#include <iostream>
#include <set>
#include <string>
#include <cassert>

//store unique elements following a specific order

class base_00
{
	int _n;
public:
	base_00(int n): _n(n) { }
	//base_00(const base_00& b){ }
	int n() const { return _n; }
	void n(int n) { _n=n; }
};

struct compare_ascending //(0 1 2)
{
	bool operator()(const base_00& b1, const base_00& b2) const
	{
		return  b1.n()<b2.n();
	}
};

struct compare_ascending_ptr //(0 1 2)
{
	bool operator()(const base_00* b1, const base_00* b2) const
	{
		assert(b1!=NULL);
		assert(b2!=NULL);
		return  b1->n()<b2->n();
	}
};

bool operator==(const base_00& b1, const base_00& b2)
{
	return b1.n()==b2.n();
}

bool operator<(const base_00& b1, const base_00& b2)
{
	return b1.n()<b2.n();
}

int main()
{
	{
		std::set<int> set;

		set.insert(3);
		set.insert(0);
		set.insert(2);
		set.insert(1);
		int i=0;
		for(std::set<int>::const_iterator it=set.begin(); it!=set.end(); ++it)
			assert(*it==i++);
		assert(*set.begin()==0);
	}
	{
		std::set<int> set;

		set.insert(2);
		std::set<int>::value_type n=*set.begin(); //value_type=int
		assert(n==2);
	}
	{
		int* a=new int(0);
		std::set<int*> set;
		std::set<int*>::const_iterator it;

		set.insert(a);
		it=set.find(a);
		assert(a==*it);
	}
	{
		std::set<base_00> set;
		//set.insert(base_00(5)); // compile error if operator<() not defined
	}
	{
		base_00 b_00(0);
		base_00 b_01(0);
		std::set<base_00> set;

		set.insert(b_00);
		set.insert(b_01);
		assert(&b_00!=&b_01);
		assert(set.size()==1); //if custom copy constructor defined, set.size()==2 ??????
	}
	{
		int* a=new int(0);
		int* b=new int(1);
		std::set<int*> set;
	
		set.insert(a);
		set.insert(a);//override
		assert(set.size()==1);
		set.insert(b);
		assert(set.size()==2);
	
		a=NULL;
		b=NULL;
		assert(set.size()==2);
		for(std::set<int*>::iterator it=set.begin(); it!=set.end(); ++it)
		{
			assert(*it!=NULL);
			assert(**it==0 || **it==1);
		}
	}
	{
		base_00 b0(5), b1(3);
		std::set<base_00, compare_ascending> set;
		set.insert(b0);
		set.insert(b1);
	
		for(std::set<base_00>::iterator it=set.begin(); it!=set.end(); ++it)
			std::cout<<it->n()<<std::endl;
	
		set.erase(base_00(3));
	
		for(std::set<base_00>::iterator it=set.begin(); it!=set.end(); ++it)
			std::cout<<it->n()<<std::endl;
	}
	{
		std::set<std::string> string_set;
		string_set.insert("one");
		string_set.insert("two");
	
		std::set<std::string>::iterator string_it=string_set.find("one");
		assert(string_it!=string_set.end());
	
		assert(*string_it=="one");
	
		string_set.erase(string_it);
	
		for(std::set<std::string>::iterator it=string_set.begin(); it!=string_set.end(); ++it)
			std::cout<<(*it)<<std::endl;
	
		base_00* b0=new base_00(0);
		base_00* b1=new base_00(1);
		base_00* b2=new base_00(2);
	
		std::set<base_00*> base_set;
		base_set.insert(b0);
		base_set.insert(b1);
		base_set.insert(b2);
	
		std::set<base_00*>::iterator base_it=base_set.find(b1);
		(*base_it)->n(5);
	
		for(std::set<base_00*>::iterator it=base_set.begin(); it!=base_set.end(); ++it)
			std::cout<<(*it)->n()<<std::endl;
	}
	{
		typedef typename std::set<base_00*, compare_ascending_ptr> base_set_type;
	
		base_set_type s;
		s.insert(new base_00(0));
		s.insert(new base_00(1));
		s.insert(new base_00(2));
	
//		base_set_type::iterator it=s.find(2);
	
		for(base_set_type::iterator it=s.begin(); it!=s.end(); ++it)
			std::cout<<(*it)->n()<<std::endl;
	}
	return 0;
}
