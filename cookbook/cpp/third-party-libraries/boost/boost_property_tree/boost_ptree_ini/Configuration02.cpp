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

	//http://duck-wrath.blogspot.co.uk/2012/02/how-to-recursive-parse.html
	std::string display(const int depth, const boost::property_tree::ptree& tree) const
	{  
		std::ostringstream oss;
		BOOST_FOREACH(boost::property_tree::ptree::value_type const& v, tree.get_child(""))
		{
			std::string	nodestr=tree.get<std::string>(v.first);
			boost::property_tree::ptree	subtree=v.second;

			//print current node
			//oss<<std::string("").assign(depth*2, ' ')<<"* ";
			oss<<std::string("").assign(depth, '\t');
			oss<<v.first;
			if(nodestr.length()>0)
				oss<<"="<<tree.get<std::string>(v.first);
			oss<<std::endl;
			
			//recursive go down the hierarchy
			oss<<display(depth+1, subtree);
		}

		return oss.str();
	}

public:
	Configuration(const std::string& filename) { load(filename); }

	template<typename T>
	T get(const std::string& name) const 
	{
		//traverse: check if value there
	}
	template<typename T>
	void set(const std::string& name, T value) 
	{
		//traverse: check if value there
	}
	template<typename T>
	void add()
	{
		//check if name unique

		//m_prop_tree.push_back(ptree::value_type("pi", ptree("3.14159")));
		//prop_tree.put("Section1.Value1", m_value1);
		//prop_tree.put("Section1.Value2", m_value2);
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
		std::ostringstream oss;
		oss<<display(0, m_prop_tree);

		return oss.str();
	}
};

int main(int argc, char* argv[])
{
	try
	{
		Configuration config("config.ini");
		/*config.setValue1(50);
		config.setValue2("text");

		config.get<int>("value1");
		config.set<int>("value1", 10);*/

		std::cout<<config.str()<<std::endl;
		//config.save("config.ini");
	}
	catch(std::exception& e)
	{
		std::cout<<"Exception: "<<e.what()<<"."<<std::endl;
		return 1;
	}

	return 0;
}
