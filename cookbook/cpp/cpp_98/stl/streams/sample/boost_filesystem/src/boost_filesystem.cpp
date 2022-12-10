#include <cassert>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>

struct base_00
{
	int	key;
	char	value;
};

void test_00()
{
	{
		base_00* a=new base_00[10];
		for(int i=0; i<10; ++i)
		{
			a[i].key=i;
			a[i].value='a';
		}

		std::ofstream ofs("data.bin", std::ios::binary);
		ofs.write((char*)a, sizeof(base_00)*10);
		ofs.close();
	}
	{
		int n=boost::filesystem::file_size("data.bin")/sizeof(base_00);
		assert(n==10);
	}
}

int main()
{
	test_00();

	return 0;
}
