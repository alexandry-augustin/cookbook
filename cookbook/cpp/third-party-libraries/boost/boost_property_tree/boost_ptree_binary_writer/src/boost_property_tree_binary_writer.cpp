#include <boost/foreach.hpp>
#include <cassert>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		boost::property_tree::ptree ptree_00("data_00");
		boost::property_tree::ptree ptree_01("data_01");
		boost::property_tree::ptree ptree_02("data_02");
		std::ofstream ofs("data.bin", std::ios::out | std::ios::binary);
		
		ptree_01.add_child("key_02", ptree_02);
		ptree_00.add_child("key_01", ptree_01);

		ofs.write((char*)&ptree_00, sizeof(ptree_00));
		ofs.close();
	}
	/*{
		base_00 b_00;

		std::ifstream ifs("data.bin", std::ios::in | std::ios::binary);
		ifs.seekg(0);
		ifs.read((char*)&b_00, sizeof(base_00));
		ifs.close();
	}*/

	return 0;
}
