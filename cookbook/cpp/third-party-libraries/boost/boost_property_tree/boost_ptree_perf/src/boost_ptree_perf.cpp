#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cassert>
#include <exception>
#include <utility>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
//---------------------------------------------------------
#define N 1000000L
//---------------------------------------------------------
struct base_00
{
	int		_n;
	std::string	_str;
	double		_d;
	mutable boost::property_tree::ptree _pt;

	base_00(int n=0): _n(n), _str("n/a"), _d(0) { }
	void to_json(std::stringstream& ss) const
	{
		ss<<"{";
		ss<<"\"int\":"<<_n;
		ss<<",\"str\":\""<<_str;
		ss<<"\",\"double\":"<<_d;
		ss<<"}";
	}
	void to_json(boost::property_tree::ptree& pt) const
	{
		_pt.put("int", _n);
		_pt.put("str", _str);
		_pt.put("double", _d);

		pt.add_child("item", _pt);
	}
};
//---------------------------------------------------------
typedef std::vector<base_00> vector_t;
//---------------------------------------------------------
void build_manual(const vector_t& v, std::stringstream& ss)
{
	ss<<"{";
	unsigned int i=0;
	for(vector_t::const_iterator it=v.begin(); it!=v.end();)	
	{
		ss<<"\"item_"<<i++<<"\":";
		it->to_json(ss);
		if(++it!=v.end())
			ss<<",";
		else
			break;
	}
	ss<<"}";
}
//---------------------------------------------------------
void build_pt(const vector_t& v, boost::property_tree::ptree& pt)
{
	for(vector_t::const_iterator it=v.begin(); it!=v.end(); ++it)	
		it->to_json(pt);
}
//---------------------------------------------------------
int main()
{
	clock_t t=clock();

	std::cout<<"N="<<N<<std::endl;

	vector_t v;
	for(unsigned int i=0; i<N; ++i)
		v.push_back(base_00(i));

	bool manual=true;
	std::stringstream ss;
	if(manual)
	{
		//vector_t => ss
		build_manual(v, ss);

		//ss => ptree
//		boost::property_tree::ptree pt;
//		std::stringstream ss_01;
//		boost::property_tree::read_json(ss, pt);
//		boost::property_tree::write_json(ss_01, pt, false);
//std::cout<<ss_01.str()<<std::endl;
	}
	else
	{
		//vector_t => ptree
		boost::property_tree::ptree pt;
		build_pt(v, pt);

		//ptree => ss
		boost::property_tree::write_json(ss, pt, false);
	}
	t=clock()-t;
	std::cout<<"cpu time:"<<(int)(t/CLOCKS_PER_SEC)<<" sec"<<std::endl;
	//std::cout<<ss.str()<<std::endl;
	return 0;
}
