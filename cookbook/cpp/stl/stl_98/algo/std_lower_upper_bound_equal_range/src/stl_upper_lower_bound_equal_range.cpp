#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>

class base_00
{
	int _n;
public:
	base_00(int n=0): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

//act as the default
bool comp_00(const base_00& left, const base_00& right)
{
	return left.get()<right.get();
}

bool comp_01(const std::vector<int>::iterator& left, const std::vector<int>::iterator& right)
{
	//return left.get()<right.get();
	return left<right;
}

struct comp_02
{
	bool operator()(const std::vector<int>::iterator& left, const int& right)
	{
		return *left<right;
	}
	bool operator()(const int& left, const std::vector<int>::iterator& right)
	{
		return left<*right;
	}
};

struct comp_03
{
	bool operator()(const std::pair<std::string, int>& lhs, const std::string& rhs) const 
	{
		return true;
	}
	bool operator()(const std::string& lhs, const std::pair<std::string, int>& rhs) const 
	{
		return true;
	}
};

int main()
{
	{
		typedef std::vector<int>	vector_t;

		int a[]={ 1, 1, 1, 2, 2, 2, 3, 3 };
		vector_t v(a, a+8);

		// std::sort(v.begin(), v.end());

		vector_t::iterator it_00=std::lower_bound(v.begin(), v.end(), 2);
		int index_00=std::distance(v.begin(), it_00);
		assert(index_00==3);
		assert(v[index_00]==2);

		vector_t::iterator it_01=std::upper_bound(v.begin(), v.end(), 2);
		int index_01=std::distance(v.begin(), it_01);
		assert(index_01==6);
		assert(v[index_01]==3);

		std::pair<vector_t::iterator, vector_t::iterator> bounds;
		bounds=std::equal_range(v.begin(), v.end(), 2);
		assert(bounds.first==it_00);
		assert(bounds.second==it_01);
	}
	{
		typedef std::vector<base_00>	vector_t;

		base_00 a[]={ 1, 1, 1, 2, 2, 2, 3, 3 };
		vector_t v(a, a+8);

		vector_t::iterator it_00=std::lower_bound(v.begin(), v.end(), base_00(2), comp_00);
		int index_00=std::distance(v.begin(), it_00);
		assert(index_00==3);
		assert(v[index_00].get()==2);

		vector_t::iterator it_01=std::upper_bound(v.begin(), v.end(), 2, comp_00);
		int index_01=std::distance(v.begin(), it_01);
		assert(index_01==6);
		assert(v[index_01].get()==3);
	}
	{
		//http://blogginman.blogspot.co.uk/2005/09/c-tip-lowerbound-and-functors.html
		std::vector<std::pair<std::string, int> > v;
		v.push_back(std::make_pair(std::string("A"), 0));
		v.push_back(std::make_pair(std::string("B"), 1));
		v.push_back(std::make_pair(std::string("C"), 2));
		v.push_back(std::make_pair(std::string("D"), 3));

		std::lower_bound(v.begin(), v.end(), std::string("C"), comp_03());
	}
	{
		typedef std::vector<int>	vector_t;
		typedef vector_t::iterator	it_t;
		typedef std::vector<it_t>	vector_it_t;

		int a_00[]={ 1, 1, 1, 2, 2, 2, 3, 3 };
		vector_t v_00(a_00, a_00+8);
		it_t a_01[]={ v_00.begin(), v_00.begin()+1, v_00.begin()+2, v_00.begin()+3, v_00.begin()+4, v_00.begin()+5, v_00.begin()+6, v_00.begin()+7 };
		vector_it_t v_01(a_01, a_01+8);

		vector_it_t::iterator it_00=std::lower_bound(v_01.begin(), v_01.end(), v_00.begin());
		vector_it_t::iterator it_01=std::lower_bound<vector_it_t::iterator>(v_01.begin(), v_01.end(), v_00.begin());

		vector_it_t::iterator it_02=std::lower_bound(v_01.begin(), v_01.end(), *v_01.begin(), comp_01);
		assert(it_02==v_01.begin());

		vector_it_t::iterator it_05=std::lower_bound(v_01.begin(), v_01.end(), 2, comp_02());
		assert(std::distance(v_01.begin(), it_05)==3);
	}
	{
		typedef std::multimap<int, char> map_t;

		map_t map;
		//map.insert(map_t::value_type(0, 'g'));
		//map.insert(map_t::value_type(1, 'u'));
		//map.insert(map_t::value_type(1, 's'));
		//map.insert(map_t::value_type(1, 'g'));
		//map.insert(map_t::value_type(4, 'u'));
		//map.insert(map_t::value_type(4, 'u'));
		//map.insert(map_t::value_type(5, 'u'));

		map.insert(std::make_pair(0, 'g'));
		map.insert(std::make_pair(1, 'u'));
		map.insert(std::make_pair(1, 's'));
		map.insert(std::make_pair(1, 'g'));
		map.insert(std::make_pair(4, 'u'));
		map.insert(std::make_pair(4, 'u'));
		map.insert(std::make_pair(5, 'u'));

		//map_t::iterator it_00=std::lower_bound(map.begin(), map.end(), 2);
		map_t::iterator it_00=map.lower_bound(1);
		std::cout<<std::distance(it_00, map.end())<<std::endl;
		//assert(std::distance(it_00, map.end())==-1);
			
		//for(map_t::iterator it=it_00; it!=map.end(); ++it)
		//	std::cout<<it->first<<" ";


		map_t::iterator it_01=it_00;
		std::advance(it_01, 4);
		for(map_t::iterator it=it_00; it!=it_01; ++it)
			std::cout<<it->first<<" ";

		map_t::iterator it_02=map.lower_bound(9);
		assert(it_02==map.end());

		map_t::iterator it_03=map.upper_bound(5);
		assert(it_03==map.end());
	}
	{
		typedef std::multimap<int, char> map_t;

		map_t map;
		map.insert(std::make_pair(2, 'g'));
		map.insert(std::make_pair(3, 'u'));
		map.insert(std::make_pair(4, 's'));

		map_t::iterator it_00=map.lower_bound(1);
		map_t::iterator it_01=map.upper_bound(1);
		assert(it_00==map.begin());
		assert(it_01==map.begin());
	}
	{
		typedef std::multimap<int, char> map_t;

		map_t map;
		map.insert(std::make_pair(2, 'g'));
		map.insert(std::make_pair(3, 'u'));
		map.insert(std::make_pair(4, 's'));

		map_t::iterator it_00=map.lower_bound(9);
		assert(it_00==map.end());
	}
	return 0;
}
