#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
//---------------------------------------------------------
struct base
{
	int n;
	std::string str;
};
//---------------------------------------------------------
void read_xml()
{
	{
		std::string msg;
		msg="<section1>";
			msg+="<value1>50</value1>";
			msg+="<value2>text</value2>";
		msg+="</section1>";
		msg+="<section2>";
			msg+="<value3>50</value3>";
			msg+="<value4>text</value4>";
		msg+="</section2>";
		std::istringstream iss(msg);
		boost::property_tree::ptree ptree;

		boost::property_tree::read_xml(iss, ptree);

		assert(ptree.get<int>("section1.value1")==50);
		assert(ptree.get<std::string>("section1.value2")=="text");
	}
	{
		std::stringstream ss;
		ss<<"<section1>";
			ss<<"<value1>50</value1>";
			ss<<"<value2>text</value2>";
		ss<<"</section1>";
		ss<<"<section2>";
			ss<<"<value3>50</value3>";
			ss<<"<value4>text</value4>";
		ss<<"</section2>";
		boost::property_tree::ptree ptree;

		boost::property_tree::read_xml(ss, ptree);

		assert(ptree.get<int>("section1.value1")==50);
		assert(ptree.get<std::string>("section1.value2")=="text");
	}
	{
		std::stringstream ss;
		ss<<"<ping>";
			ss<<"<timeout>10</timeout>";
		ss<<"</ping>";
		ss<<"<pong>";
			ss<<"<timeout>5</timeout>";
			ss<<"<desc>";
				ss<<"<str>some desc</str>";
			ss<<"</desc>";
		ss<<"</pong>";
		boost::property_tree::ptree ptree;
	
		boost::property_tree::read_xml(ss, ptree);
		//-----------------------------------------
//		std::stringstream ss;
//		boost::property_tree::xml_writer_settings<char> w(' ', 4);
//		boost::property_tree::write_xml(ss, ptree, w);
//		std::cout<<ss.str()<<std::endl;
		//-----------------------------------------
		//boost::property_tree::ptree::not_found()
		boost::property_tree::ptree::assoc_iterator it=ptree.find("data");
		//-----------------------------------------
		assert(ptree.find("ping")!=ptree.not_found());
		assert(ptree.find("pong")!=ptree.not_found());
		assert(ptree.find("ping.timeout")==ptree.not_found());
		assert(ptree.find("pong.timeout")==ptree.not_found());
	}
	{
		boost::property_tree::ptree ptree;
	
		boost::property_tree::read_xml("in.xml", ptree);

		assert(ptree.get<int>("section1.value1")==50);
		assert(ptree.get<std::string>("section1.value2")=="text");
	
		boost::property_tree::ptree::const_iterator it=ptree.begin();
		assert(it->first=="section1");
		assert(it->second.begin()->first=="value1");
//		std::cout<<(it->second.begin()+1)->first<<std::endl;
	}
}
//---------------------------------------------------------
void write_xml()
{
	{
		boost::property_tree::ptree ptree;
		base b;
	
		b.n=5;
		b.str="text";
		ptree.put("section1.value1", b.n);
		ptree.put("section1.value2", b.str);

		boost::property_tree::write_xml("out.xml", ptree); //will create the file
	}
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	read_xml();
	write_xml();
}
