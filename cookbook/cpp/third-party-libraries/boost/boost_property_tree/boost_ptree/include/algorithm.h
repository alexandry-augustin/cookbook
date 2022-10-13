//#include <sstream>
//#include <iostream>
//#include <exception>
//#include <string>
//#include <vector>
#include <boost/foreach.hpp>
#include <cassert>
#include <boost/property_tree/ptree.hpp>
//#include <boost/algorithm/string.hpp>
//---------------------------------------------------------
void to_string(std::ostream& os, const boost::property_tree::ptree& ptree) //only for a single level
{
	for(boost::property_tree::ptree::const_iterator it=ptree.begin(); it!=ptree.end(); ++it)
		os<<it->first<<":"<<it->second.get_value<std::string>()<<";";
	//or
	//BOOST_FOREACH(const boost::property_tree::ptree::value_type& v, ptree)
	//	os<<v.first<<":"<<v.second.data()<<";";
}
//---------------------------------------------------------
/*bool check(const int depth, const boost::property_tree::ptree& tree) const
{  
	bool is_valid=false;

	BOOST_FOREACH(const boost::property_tree::ptree::value_type& v, tree.get_child(""))
	{
		std::string key=tree.get<std::string>(v.first);
		boost::property_tree::ptree child_tree=v.second;

		//recursive go down the hierarchy
		if(ptree.find(key[0])==ptree.not_found())
			is_valid=check(depth+1, subtree);
	}

	return is_valid;
}
//---------------------------------------------------------
bool is_valid_path(const boost::property_tree::ptree& ptree, std::string path)
{
	std::vector<std::string> key;
	boost::split(key, path, boost::is_any_of("."));

	if(key.empty())
		return false;

	if(ptree.find(key[0])==ptree.not_found())
		return false;

	key.erase(key.begin());
	//is_valid_path(ptree.get_child(), new_path);
}*/
//---------------------------------------------------------
/*bool check(const boost::property_tree::ptree& ptree, std::string path)
{
	std::vector<std::string> key;
	boost::split(key, path, boost::is_any_of("."));

	for(boost::property_tree::ptree::const_iterator it=ptree.begin(); it!=ptree.end(); ++it)
	{
		if(it->first==key[0])
		key.erase(key.begin());
		return check(it->second, boost::algorithm::join(key, "."));
	}
}*/
//---------------------------------------------------------
//returns all possible paths
/*std::vector<std::string> paths(const boost::property_tree::ptree& ptree)
{
	std::stringstream ss;
	std::vector<std::string> ret;
	BOOST_FOREACH(const boost::property_tree::ptree::value_type& v, ptree.get_child(""))
	{
		//ret.push_back(tree.get<std::string>(v.first));
//		paths(subtree);
	}

	return ss.str();
}*/
