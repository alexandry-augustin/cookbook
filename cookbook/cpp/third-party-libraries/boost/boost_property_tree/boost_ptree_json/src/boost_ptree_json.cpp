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
void build_json()
{
	{
		//{
		//    "field_00": "0",
		//    "field_01": "1",
		//    "field_02":
		//    [
		//        "2",
		//        {
		//            "field_03": "5"
		//        },
		//        "9"
		//    ]
		//}
		boost::property_tree::ptree pt_00;
		boost::property_tree::ptree pt_01;

		pt_00.add("field_00", "0");
		pt_00.add("field_01", "1");
		pt_00.add("field_02", "");

		pt_01.put("", 2);
		pt_00.get_child("field_02").push_back(std::make_pair("", pt_01));

		pt_01.clear();
		pt_01.put("field_03", 5);
		pt_00.get_child("field_02").push_back(std::make_pair("", pt_01));

		pt_01.clear();
		pt_01.put("", 9);
		pt_00.get_child("field_02").push_back(std::make_pair("", pt_01));

		//write to stringstream
		std::stringstream oss;
		boost::property_tree::write_json(oss, pt_00, false);
		assert(oss.str()=="{\"field_00\":\"0\",\"field_01\":\"1\",\"field_02\":[\"2\",{\"field_03\":\"5\"},\"9\"    ]}\n"); // always ends by \n
	}
	{
		// {
		//     "level_00":
		//     {
		//         "level_01":
		//         [
		//             {
		//                 "field_00": "00",
		//                 "field_01": "01",
		//                 "field_02": "02"
		//             },
		//             {
		//                 "field_00": "00",
		//                 "field_01": "01",
		//                 "field_02": "02"
		//             }
		//         ]
		//     }
		// }
		boost::property_tree::ptree pt;
		boost::property_tree::ptree item;
		boost::property_tree::ptree array;

		item.put("field_00", "00");
		item.put("field_01", "01");
		item.put("field_02", "02");

		array.push_back(std::make_pair("", item));
		array.push_back(std::make_pair("", item));

		pt.add("level_00", "");

		pt.get_child("level_00").push_back(std::make_pair("level_01", array));

		//_data.get_child("header."+section).push_back(std::make_pair("", item));

		std::stringstream oss;
		boost::property_tree::write_json(oss, pt, false);
		//std::cout<<oss.str()<<std::endl;
	}
}
//---------------------------------------------------------
void read_json()
{
	{
		std::stringstream ss;
		ss<<"{";
			ss<<"\"field_00\": 0,";
			ss<<"\"field_01\": \"1\",";
			ss<<"\"field_02\": 2";
		ss<<"}";
		boost::property_tree::ptree pt;

		boost::property_tree::read_json(ss, pt);

		assert(pt.get_value<std::string>().empty());

		assert(pt.get_child("field_00").data()=="0");
		assert(pt.get_child("field_01").data()=="1");
		assert(pt.get_child("field_02").data()=="2");

		assert(pt.get<int>("field_00")==0);
		assert(pt.get<int>("field_01")==1);
		assert(pt.get<int>("field_02")==2);
	}
	{
		std::stringstream ss;
		ss<<"{";
			ss<<"\"field_00\": {";
				ss<<"\"field_01\": 5";
       				ss<<"}";
		ss<<"}";
		boost::property_tree::ptree pt;

		boost::property_tree::read_json(ss, pt);

		assert(pt.get_child("field_00.field_01").data()=="5");
	}
	{
		std::stringstream ss;
		ss<<"{";
	       		ss<<"\"field_00\": [1, 2, \"3\", 4, 5]";
       		ss<<"}";
		boost::property_tree::ptree pt;

		boost::property_tree::read_json(ss, pt);

		assert(pt.get_value<std::string>().empty());

		int i=1;
		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, pt.get_child("field_00"))
		{
			assert(v.first.empty()); // array nodes have no key names
			assert(v.second.get_value<int>()==i);
			assert(v.second.get<int>("")==i);
			++i;
		}
	}
	{
		std::stringstream ss;
		ss<<"{";
			ss<<"\"field_00\": [{";
				ss<<"\"field_01\": 0";
       				ss<<"}, {";
				ss<<"\"field_01\": 1";
			ss<<"}]";
		ss<<"}";
		boost::property_tree::ptree pt;

		boost::property_tree::read_json(ss, pt);

		int i=0;
		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, pt.get_child("field_00"))
		{
			assert(v.first.empty());
			assert(v.second.get<int>("field_01")==i);
			++i;
		}
	}
	{
		std::stringstream ss;
		ss<<"{";
	       		ss<<"\"field_00\": [{\"one\":1,\"two\":2}, {\"three\":3,\"four\":4}]";
       		ss<<"}";
		boost::property_tree::ptree pt;

		boost::property_tree::read_json(ss, pt);

		int i=0;
		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, pt.get_child("field_00"))
		{
			assert(v.first.empty()); // array nodes have no key names
			assert(v.second.get_value<std::string>().empty());
			if(i==0)
			{
				assert(v.second.get_child("one").get_value<int>()==1);
				assert(v.second.get_child("two").get_value<int>()==2);
				++i;
			}
			else if(i==1)
			{
				assert(v.second.get_child("three").get_value<int>()==3);
				assert(v.second.get_child("four").get_value<int>()==4);
			}
		}
	}
}
//---------------------------------------------------------
void write_json()
{
	{
		std::stringstream ss;
		ss<<"{";
			ss<<"\"field_00\": 0,";
			ss<<"\"field_01\": \"1\",";
			ss<<"\"field_02\": [2, {\"field_03\": 5}, 9]";
		ss<<"}";
		boost::property_tree::ptree pt;

		//write to file
		boost::property_tree::read_json(ss, pt);
		boost::property_tree::write_json("out.json", pt); //will create the file and pretty print ss

		//write to stringstream
		std::stringstream oss;
		boost::property_tree::write_json(oss, pt, false);
		assert(oss.str()=="{\"field_00\":\"0\",\"field_01\":\"1\",\"field_02\":[\"2\",{\"field_03\":\"5\"},\"9\"    ]}\n"); // always ends by \n
	}
}
//---------------------------------------------------------
int main()
{
	build_json();
	read_json();
	write_json();
	{
		std::stringstream ss;
		ss<<"invalid";
		boost::property_tree::ptree pt;
		bool error=false;

		try
		{
			boost::property_tree::read_json(ss, pt);
		}
		catch(const boost::property_tree::json_parser::json_parser_error& e)
		{
			error=true;
		}
		assert(error);	
	}
	return 0;
}
