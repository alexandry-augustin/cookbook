#include <iostream>
#include <cassert>
#include <map>
#include <algorithm>
#include <boost/bind.hpp>

template< typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator copy_if(InputIterator begin, InputIterator end, OutputIterator dest_begin, Predicate pred)
{
	while(begin!=end)
	{
		if(pred(*begin))
			*dest_begin++=*begin;
		++begin;
	}
	return dest_begin;
};

struct base_00
{
	base_00(int n_=0): n(n_) { }
	int n;
};

typedef std::string					first_type;
typedef base_00*					second_type;
typedef typename std::map<first_type, second_type>	base_map_type;

//base_00* operator[](second_type lhs, first_type rhs)
//{
//}

struct base_01
{
	std::map<std::string, int> _m;
	int get_00(std::string str) const
	{
		std::map<std::string, int>::const_iterator it=_m.find(str);
		assert(it!=_m.end());
		return it->second;
	}
	int get_01(std::string str) //const
	{
		return _m[str];
	}
	void add(std::string str, int n)
	{
		assert(_m.find(str)==_m.end());
		_m.insert(std::make_pair(str, n));
	}
	void set_or_add1(std::string str, int n)
	{
		_m[str]=n;
	}
	int get_or_add_and_get(std::string str, int n)
	{
		std::map<std::string, int>::const_iterator it=_m.find(str);
		if(it!=_m.end())
			return it->second;
		else
		{
			_m.insert(std::make_pair(str, n));
			return _m.find(str)->second;
		}
	}
	void set(std::string str, int n)
	{
		std::map<std::string, int>::iterator it=_m.find(str);
		assert(it!=_m.end());
		it->second=n;
	}
};

class base_02
{
	int* _n;
public:
	base_02(int n): _n(new int(n)) {}
	int* get_n() const { return _n; }
};

struct base_03
{
	base_03(int n_): n(n_) {}
	int n;
	bool operator<(const base_03& b) const
	{
		return n<b.n;
	}
};

template<class T>
struct map_unary
{
	bool operator()(typename T::value_type& pair) const
	{
		return false;
	}
};

template<class T>
struct map_binary:
	public std::binary_function<typename T::value_type, typename T::mapped_type, bool>
{
	bool operator()(typename T::value_type& pair, typename T::mapped_type i) const
	{
		return pair.second==i;
	}
};

int main()
{
	{
		std::map<base_03, int> m;
		m[base_03(4)]=0; //compile error if '<' not overriden
		m[base_03(3)]=1;
		m[base_03(2)]=2;
	}
	{
		base_01 b;
		b.add("one", 1);
		assert(b.get_00("one")==1);
		assert(b._m.find("one")->second==1);
		b.set_or_add1("two", 2);
		assert(b.get_01("two")==2);
		b.set("one", -1);
		assert(b.get_00("one")==-1);
		assert(b.get_or_add_and_get("three", 3)==3);
	}
	{
		base_map_type base_map;
//		base_map["one"]=new base_00(1);
//		assert(base_map["one"].n=1);
	}
	{
		typedef std::map<std::string, int> map;
		map m;
	
		//note: std::map::operator[] has "side effect". In case, that key value is
		//not present in map, new one is added.
		m["one"]=1;
		m["two"]=2;
		m["three"]=3;
	
		m["one"]=3; //overriden?
	
		map::iterator it=m.find("two");
		assert(it->second==2);
	
		m.insert(std::pair<std::string, int>("five", 5));
		m.insert(m.begin(), std::pair<std::string, int>("four", 4));
	
		m.erase("two");
	
		for(std::map<std::string, int>::const_iterator it=m.begin(); it!=m.end(); ++it)
			std::cout<<"["<<it->first<<":"<<it->second<<"]"<<std::endl;
	}
	{
		typedef std::map<int, char>		inner_map_type;
		typedef std::map<int, inner_map_type>	map_type;
	
		map_type map;
		map_type::iterator map_it;
		
		map[0][0]='A';
		map[0][1]='B';
		map[1][0]='C';
		map[1][1]='D';
		map[2].insert(std::pair<int, char>(0, 'E'));
	
		/* works but shacky if int are not continuous
		int i=0;
		int j=0;
		for(map_type::iterator it=map.begin(); it!=map.end(); ++it)
		{
			for(inner_map_type::iterator inner_it=it->second.begin(); inner_it!=it->second.end(); ++inner_it)
			{
				std::cout<<"map["<<i<<"]["<<j<<"]="<<map[i][j]<<std::endl;
				++j;
			}
			j=0;
			++i;
		}*/
	
		for(map_type::iterator it=map.begin(); it!=map.end(); ++it)
			for(inner_map_type::iterator inner_it=it->second.begin(); inner_it!=it->second.end(); ++inner_it)
				std::cout<<"map["<<it->first<<"]["<<inner_it->first<<"]"<<"="<<inner_it->second<<std::endl;
	
		std::cout<<"map["<<1<<"]["<<1<<"]="<<map[1][1]<<std::endl;
	
		map_it=map.find(2);
		assert(map_it!=map.end());
	}
	{
		base_map_type map;
		base_00* base_0=new base_00(0);
		base_00* base_1=new base_00(1);
		base_00* base_2=new base_00(2);
		map["A"]=base_0;
		map["B"]=base_1;
		map["C"]=base_2;
	
		base_map_type::const_iterator it=
			std::find_if(map.begin(), map.end(),
			boost::bind(&base_map_type::value_type::second, _1)==base_1);
	
		assert(it->second==base_1);
	}
	{
		base_map_type map, map_copy;
		base_00* base_0=new base_00(0);
		base_00* base_1=new base_00(1);
		base_00* base_2=new base_00(2);
		map["A"]=base_0;
		map["B"]=base_1;
		map["C"]=base_2;
	
		copy_if(map.begin(), map.end(),
			std::inserter(map_copy, map_copy.end()), 
			boost::bind(&base_map_type::value_type::second, _1)>base_0);
	
		for(base_map_type::const_iterator it=map_copy.begin(); it!=map_copy.end(); ++it)
			std::cout<<"["<<it->first<<":"<<it->second->n<<"]"<<std::endl;
	}
	{
		std::map<std::string, int> m;
		m["test"]=5;
		std::string str("test");
		m[str]=9;
		std::cout<<m["test"]<<std::endl;
	}
	{
		typedef typename std::map<std::string, int*>	map_type;
		map_type		map;
		map_type::iterator	it;
		map_type::value_type	value_type; //pair<const std::string, int*>
	
		map["zero"]=new int(0);
		map["one"]=new int(1);
		map["two"]=new int(2);
	
		it=map.begin();
		++it;
		assert(*it->second==2);
	
		map_type::value_type	value_type_(it->first, it->second);
	
		//value_type.first=it->first; //nok: value_type.first is const
		value_type.second=it->second;
		assert(*value_type.second==2);
	
		it=std::find_if(map.begin(), map.end(), map_unary<map_type>());
	
/*		const int n=2;
		//it=std::find_if(map.begin(), map.end(), std::bind2nd(map_binary<map_type>(), n));
		assert(it!=map.end());
		assert(n==*it->second);*/
	}
	{
		typedef typename std::map<std::string, base_02*>	map_type;
		map_type		map;
		map_type::iterator	it;

		map["zero"]=new base_02(0);
		map["one"]=new base_02(1);
		map["two"]=new base_02(2);
	
		it=map.begin();
		map_type::value_type value_type(it->first, it->second);
		assert(*(boost::bind(&base_02::get_n,
			boost::bind(&map_type::value_type::second, value_type))())==1);
		assert(*boost::bind(&base_02::get_n,
			boost::ref(value_type.second))()==1);
		//assert(boost::bind(&base_02::get_n,
		//	boost::bind(&map_type::value_type::second, value_type))()==it->second);
		//assert(boost::bind(&base_02::get_n,
		//	boost::ref(value_type.second))()==it->second);
	}
	{
		typedef typename std::map<std::string, base_02*>	map_type;
		map_type		map;
		map_type::iterator	it;
	
		map["zero"]=new base_02(0);
		map["one"]=new base_02(1);
		map["two"]=new base_02(2);
	
		std::for_each(map.begin(), map.end(),
			boost::bind(&map_type::value_type::second, _1)
			);
	}
	{
		typedef typename std::map<int, std::string>	map_t;

		map_t m;
		m[0]="zero";
		
		map_t::value_type item=*m.begin(); //std::pair<int, std::string>
		assert(item.first==0);
		assert(item.second=="zero");
	}
	{
		typedef typename std::map<int, int>	map_t;

		map_t m;
		m.insert(map_t::value_type(0, 0));
		m.insert(map_t::value_type(0, 0));
		m.insert(map_t::value_type(1, 0));

		assert(m.size()==2);
	}
	{
		std::map<int, int>	map;
		map.clear();
	}
	{
		std::map<int, int>	map;

		assert(map[999]==0);
		assert(map.size()==1);
	}
	{
		//sorting order
		std::map<int, std::string>	map;

		map[6]="six";
		map[0]="zero";
		map[4]="four";

		assert(map.begin()->first==0);
		assert(map.rbegin()->first==6);
	}
	return 0;
}
