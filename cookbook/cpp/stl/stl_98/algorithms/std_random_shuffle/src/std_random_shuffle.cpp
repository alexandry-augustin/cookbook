#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> //rand() srand()
#include <ctime> //time()

class base_00 
{
	int m_n;
public:
	friend std::ostream& operator<<(std::ostream& out, const base_00& c);

	base_00(int n=0): m_n(n) { }
	base_00(const base_00 &c): m_n(c.m_n) { }
	size_t operator()(size_t n) const { return(rand()%n ); }
};

//random-number generation functor
class base_01
{
public:
	size_t operator()(size_t n) const { return rand()%n; }
};

std::ostream& operator<<(std::ostream& out, const base_00& c)
{
	out<<c.m_n;
	return out;
}

int main() 
{
	{
		std::vector<base_00> v;
		v.push_back(5);
		v.push_back(0);
		v.push_back(7);
		v.push_back(1);
		v.push_back(4);
		
		for(unsigned i=0; i<v.size(); ++i)
			std::cout<<v[i]<<" ";
		std::cout<<std::endl;

		srand(unsigned(time(NULL)));
		
		base_01 rnd;
		std::random_shuffle(v.begin(), v.end(), rnd);
		//or
	//	std::random_shuffle(v.begin(), v.end(), base_00());

		for(unsigned i=0; i<v.size(); ++i)
			std::cout<<v[i]<<" ";
		std::cout<<std::endl;
	}
	return 0;
}
