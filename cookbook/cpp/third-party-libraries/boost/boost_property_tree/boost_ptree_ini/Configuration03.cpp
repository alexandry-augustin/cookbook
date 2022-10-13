#include <iostream>
#include <exception>
#include <string>
#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/foreach.hpp>

class Configuration
{
	boost::property_tree::ptree m_prop_tree;

	std::string nodeStr(const int depth, const boost::property_tree::ptree& tree) const
	{  
		std::ostringstream oss;
		BOOST_FOREACH(boost::property_tree::ptree::value_type const& v, tree.get_child(""))
		{
			std::string nodestr=tree.get<std::string>(v.first);
			boost::property_tree::ptree subtree=v.second;

			//print current node
			if(nodestr.length()==0)
				oss<<"["<<v.first<<"]";
			else
				oss<<v.first<<"="<<tree.get<std::string>(v.first);
			oss<<std::endl;
			
			//recursive go down the hierarchy
			oss<<display(depth+1, subtree);
		}

		return oss.str();
	}
public:
	Configuration(const std::string& filename) { load(filename); }

	template<typename T>
	T get(const std::string& section, const std::string& name) const 
	{
		return m_prop_tree.get<T>(section+"."+name);	
	}
	template<typename T>
	void set(std::string section, const std::string& name, T value) //add if absent, update if present
	{
		//m_prop_tree.push_back(boost::property_tree::ptree::value_type("pi", boost::property_tree::ptree("3.14159")));
		if(!section.empty()) section.append(".");
		m_prop_tree.put(section+name, value);
	}
	void load(const std::string &filename)
	{
		return boost::property_tree::ini_parser::read_ini(filename, m_prop_tree);
	}
	void save(const std::string &filename)
	{
		boost::property_tree::ini_parser::write_ini(filename, m_prop_tree);
	}
	std::string str() const
	{  
		std::stringstream oss;
		oss<<display(0, m_prop_tree);

		return oss.str();
	}
};

int main(int argc, char* argv[])
{
	try
	{
		Configuration config("config.ini");
		std::cout<<config.str()<<std::endl;

		config.set("", "Value1", 34);
		config.set("Section1", "Value1", 34);
		std::cout<<config.get<int>("Section1", "Value1")<<std::endl;
		std::cout<<config.get<std::string>("Section1", "Value2")<<std::endl;

		std::cout<<config.str()<<std::endl;
		config.save("config_.ini");
	}
	catch(std::exception& e)
	{
		std::cout<<"Exception: "<<e.what()<<"."<<std::endl;
		return 1;
	}

	return 0;
}
