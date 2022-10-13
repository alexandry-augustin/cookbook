#include <boost/foreach.hpp>
#include <cassert>
#include <boost/property_tree/ptree.hpp>
#include "algorithm.h"
//---------------------------------------------------------
void constructors()
{
	{
		//default constructor
		boost::property_tree::ptree ptree;

		assert(ptree.size()==0);
		assert(ptree.empty());

		assert(ptree.data().empty());
		assert(ptree.data()=="");
		assert(ptree.get_value<std::string>().empty());
	}
	{
		boost::property_tree::ptree ptree("data_00");

		assert(ptree.empty());
		assert(ptree.data()=="data_00");
	}
	{
		//copy constructor
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01(ptree_00); //takes a copy

		assert(ptree_00.data()=="data_00");
		ptree_00.data()="data_01";
		assert(ptree_01.data()=="data_00");
	}
	{
		int n=5;
	//	boost::property_tree::ptree ptree(n); //nok
	}
}
//---------------------------------------------------------
void data_manip()
{
	//data() get_value() put_value() - no such thing as add_value()
	{
		boost::property_tree::ptree ptree;

		assert(ptree.data().empty());
		//data() returns a ref on data
		ptree.data()="data_00";
		assert(ptree.data()=="data_00");

		ptree.put_value("data_01");
		assert(ptree.get_value<std::string>()=="data_01");
		assert(ptree.data()=="data_01");

		ptree.put_value(5);
		assert(ptree.get_value<std::string>()=="5");
		assert(ptree.get_value<int>()==5);
		assert(ptree.data()=="5");
		//assert(ptree.data()==5); //nok
	}
	{
		boost::property_tree::ptree ptree;

		ptree.push_back(std::make_pair("key_01", "data_01"));
		assert(ptree.size()==1);
	}
	{
		//clear()
		boost::property_tree::ptree ptree("data_00");

		assert(!ptree.data().empty());
		ptree.push_back(std::make_pair("key_01", "data_01"));
		assert(ptree.size()==1);

		ptree.clear();
		assert(ptree.data().empty());
		assert(ptree.empty());
	}
}
//---------------------------------------------------------
void get_child_00()
{
	{
		boost::property_tree::ptree ptree_00("data_00");
		bool error=false;

		try
		{
			ptree_00.get_child("unknown_key"); //throws on unknown key
		}
		catch(const boost::property_tree::ptree_error& e) //Base class for all property tree errors. Derives from std::runtime_error
		{
			error=true;
		}
		assert(error);
	}
	{
		boost::property_tree::ptree ptree;
		boost::property_tree::ptree default_ptree("default");
		boost::property_tree::ptree buf;

		buf=ptree.get_child("unknown_key", default_ptree); //use default value for unknown key
		assert(buf.data()=="default");
	}
	{
		//TODO
		boost::property_tree::ptree ptree;
		//boost::optional buf;

		//buf=
		ptree.get_child_optional("unknown_key");
	}
	{
		boost::property_tree::ptree ptree_00;
		boost::property_tree::ptree ptree_01;
		ptree_00.add_child("key_01", ptree_01);

		boost::optional<boost::property_tree::ptree> ptree_02(ptree_00.get_child_optional("key_01"));
		assert(ptree_02);

		boost::optional<boost::property_tree::ptree> ptree_03(ptree_00.get_child_optional("unknown_key"));
		assert(!ptree_03);
	}
	{
		boost::property_tree::ptree ptree_00("5");

		boost::optional<int> n=ptree_00.get_optional<int>("");
		assert(n==5);
	}
}
//---------------------------------------------------------
void get_child_01()
{
	{
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01("data_01");
		boost::property_tree::ptree ptree_02("data_02");
		
		ptree_01.add_child("key_02", ptree_02); //the order of those 2 lines is important
		ptree_00.add_child("key_01", ptree_01);
		
		assert(ptree_00.size()==1);
		assert(ptree_01.size()==1);
		assert(ptree_02.empty());

		assert(ptree_00.get_child("key_01").data()=="data_01");
		assert(ptree_00.get_child("key_01").get_child("key_02").data()=="data_02");
		assert(ptree_00.get_child("key_01.key_02").data()=="data_02"); // ==ptree_00.get() without cast?
	}
}
//---------------------------------------------------------
void shorthands()
{
	//put() get() add()
	{
		//get()
		boost::property_tree::ptree pt;
		int n;

		n=pt.get("key_01", 99);//with default value if not found
		assert(n==99);

		pt.push_back(std::make_pair("key_01", "16"));
		n=pt.get<int>("key_01");
		assert(n==16);

	}
	{
		//get()
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01("data_01");
		boost::property_tree::ptree ptree_02("data_02");
		
		//the order of those 2 lines is important (add in reverse order)
		ptree_01.add_child("key_02", ptree_02);
		ptree_00.add_child("key_01", ptree_01);

		assert(ptree_00.get_child("key_01").get_child("key_02").get_value<std::string>()=="data_02");
		assert(ptree_00.get<std::string>("key_01.key_02")=="data_02");
		assert(ptree_00.get<std::string>("key_01.key_02").data()==ptree_00.get_child("key_01").get_child("key_02").get_value<std::string>());

		bool error=false;
		try
		{
			ptree_00.get<std::string>("key_01.key_02"); //throws on unknown key
		}
		catch(const boost::property_tree::ptree_error& e)
		{
			error=true;
		}
		assert(!error);
	}
	{
		//add()
		boost::property_tree::ptree ptree_00("data_00");

		ptree_00.add("key_01", "data_01");
		assert(ptree_00.size()==1);

		ptree_00.add("key_01", "data_01");
		assert(ptree_00.size()==2);
	}
	{
		//add()
		boost::property_tree::ptree ptree_00("data_00");

		//If the node identified by the path does not exist, create it, including all its missing parents.
		//If the final node already exists, add a sibling with the same key.
		ptree_00.add("key_01.key_02.key_03", "data_03");

		assert(ptree_00.size()==1);
		assert(ptree_00.get_child("key_01").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").empty());
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").data()=="data_03");

		ptree_00.add("key_01.key_02.key_03", "data_03");

		assert(ptree_00.size()==1);
		assert(ptree_00.get_child("key_01").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").size()==2);
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").empty());
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").data()=="data_03");
	}
	{
		//put()
		boost::property_tree::ptree ptree_00("data_00");

		ptree_00.put("key_01", "data_01");
		assert(ptree_00.size()==1);

		ptree_00.put("key_01", "data_01");
		assert(ptree_00.size()==1);
	}
	{
		//put()
		boost::property_tree::ptree ptree_00("data_00");

		//If the node identified by the path does not exist, create it, including all its missing parents.
		//If the final node already exists, replace it
		ptree_00.put("key_01.key_02.key_03", "data_03");

		assert(ptree_00.size()==1);
		assert(ptree_00.get_child("key_01").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").empty());
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").data()=="data_03");

		ptree_00.put("key_01.key_02.key_03", "data_03");

		assert(ptree_00.size()==1);
		assert(ptree_00.get_child("key_01").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").size()==1);
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").empty());
		assert(ptree_00.get_child("key_01").get_child("key_02").get_child("key_03").data()=="data_03");
	}
}
//---------------------------------------------------------
void iterators()
{
	{
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01("data_01");
		boost::property_tree::ptree ptree_02("data_02");
		boost::property_tree::ptree::const_iterator it;
		
		ptree_00.add_child("key_01", ptree_01);
		ptree_00.add_child("key_02", ptree_02);

		assert(ptree_00.size()==2);

		it=ptree_00.begin();
		assert(it->first=="key_01");
		assert(it->second.data()=="data_01");

		++it;
		assert(it->first=="key_02");
		assert(it->second.data()=="data_02");

		std::ostringstream oss;
		to_string(oss, ptree_00);
		assert(oss.str()=="key_01:data_01;key_02:data_02;");

		ptree_00.clear();
		assert(ptree_00.empty());
	}
	{
		boost::property_tree::ptree ptree_00;
		boost::property_tree::ptree ptree_01("data_01");

		ptree_00.push_back(boost::property_tree::ptree::value_type("key_01", ptree_01));
		boost::property_tree::ptree::const_assoc_iterator it=ptree_00.find("key_01");
		assert(it!=ptree_00.not_found());
	}
}
//---------------------------------------------------------
void non_unique_nodes()
{
	{
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01("data_01");
		boost::property_tree::ptree ptree_02("data_02");

		ptree_00.add_child("key", ptree_01);
		ptree_00.add_child("key", ptree_02);

		assert(ptree_00.size()==2);
		assert(ptree_00.get_child("key").data()=="data_01"); //return the first found from begin()
	}
	{
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01("data_01");
		boost::property_tree::ptree ptree_02("data_02");
		boost::property_tree::ptree::const_iterator it;

		ptree_00.add_child("key", ptree_01);
		ptree_00.add_child("key", ptree_02);

		assert(ptree_00.size()==2);

		it=ptree_00.begin();
		assert(it->first=="key");
		assert(it->second.data()=="data_01");

		++it;
		assert(it->first=="key");
		assert(it->second.data()=="data_02");
	}
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	constructors();
	data_manip();
	get_child_00();
	get_child_01();
	iterators();
	shorthands();
	non_unique_nodes();

	return 0;
}
