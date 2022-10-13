#include <iostream>
#include <exception>
#include <string>
#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class Configuration
{
	int		m_value1;
	std::string	m_value2;
public:
	Configuration(){ setDefault(); }

	int getValue1() const { return m_value1; }
	void setValue1(int value) { m_value1=value; }

	std::string getValue2() const { return m_value2; }
	void setValue2(std::string value) { m_value2=value; }

	void setDefault()
	{
		setValue1(0);
		setValue2("");
	}
	void load(const std::string &filename)
	{
		boost::property_tree::ptree prop_tree;
		boost::property_tree::ini_parser::read_ini(filename, prop_tree);

		m_value1=prop_tree.get<int>("Section1.Value1");
		m_value2=prop_tree.get<std::string>("Section1.Value2");
	}
	void save(const std::string &filename)
	{
		boost::property_tree::ptree prop_tree;

		prop_tree.put("Section1.Value1", m_value1);
		prop_tree.put("Section1.Value2", m_value2);
		boost::property_tree::ini_parser::write_ini(filename, prop_tree);
	}
	std::string str() const
	{
		std::stringstream ss;
		ss<<"Value1="<<m_value1<<std::endl;
		ss<<"Value2="<<m_value2;

		return ss.str();
	}
};

int main(int argc, char* argv[])
{
	try
	{
		Configuration conf;
		conf.load("config.ini");
		conf.setValue1(50);
		conf.setValue2("text");
		std::cout<<conf.str()<<std::endl;
		conf.save("config.ini");
	}
	catch(std::exception& e)
	{
		std::cout<<"Exception: "<<e.what()<<"."<<std::endl;
	}

	return 0;
}
