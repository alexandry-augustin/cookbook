#include <cassert>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
//---------------------------------------------------------
int main()
{
	{
		boost::filesystem::path path("data_99");

		//assert(path.parent_path()=="./data");
		std::cout<<path.parent_path();
	}
/*	{
		boost::filesystem::path path_00;
		boost::filesystem::path path_01;

		assert(path_00.empty());

		path_00="data";
		path_01="data";
		assert(path_00==path_01);

		path_00="data/data_00.ext";
		path_01="data/data_01";
		assert(path_00!=path_01);
	}
	{
		boost::filesystem::path path("data");

		assert(boost::filesystem::exists(path));
		assert(boost::filesystem::is_directory(path));
		assert(!boost::filesystem::is_empty(path));
		assert(!boost::filesystem::is_regular_file(path));

		path="data/data_00.ext";

		assert(boost::filesystem::exists(path));
		assert(!boost::filesystem::is_directory(path));
		assert(boost::filesystem::is_regular_file(path));
	}
	{
		bool exist=boost::filesystem::exists("data/data_00.ext");
		assert(exist);
	}
	//{
	//	uintmax_t size=boost::filesystem::file_size("data/data_00.ext");
	//	assert(size>=0);
	//}
	{
		//iterate through directory
		boost::filesystem::path path("data");
		boost::filesystem::directory_iterator end;
		for(boost::filesystem::directory_iterator it(path); it!=end; ++it)
		{
			assert(it->path()==*it); //????        
			boost::filesystem::path cur_path=*it;

			//will get files and directories
			std::cout<<it->path();
			std::cout<<"    ";
			std::cout<<it->path().string();
			std::cout<<"    ";
			std::cout<<it->path().filename();
			std::cout<<"    ";
#if (BOOST_VERSION > 105000)
			std::cout<<it->path().filename().string();
#else
			std::cout<<it->path().filename().c_str();
#endif
			std::cout<<'\n';
		}

		boost::filesystem::directory_iterator it(path);
		BOOST_FOREACH(const boost::filesystem::path& path, std::make_pair(it, end))
		{
			if(!boost::filesystem::is_directory(path))
				assert(boost::filesystem::is_regular_file(path));
		}
	}
	{
		boost::filesystem::path path("./data/data_00.ext");

		//for(boost::filesystem::path::iterator it=path.begin(); it!=path.end(); ++it)
		boost::filesystem::path::iterator it=path.begin();
		assert(*it==".");

		++it;
		assert(*it=="data");

		++it;
		assert(*it=="data_00.ext");

		assert(path.string()=="./data/data_00.ext");
		assert(path.filename()=="data_00.ext");
		boost::filesystem::path rel_path=path.relative_path();
		assert(path.relative_path()=="./data/data_00.ext"); //returns a path
		assert(path.parent_path()=="./data"); //fullpath without .filename() (i.e. ./data/dir/)

//		path.absolute("");

		//std::cout<<path.parent_path();
	}*/
	{
		boost::filesystem::path path("./data/dir/data_00");
		assert(path.parent_path()=="./data/dir");
	}
	/*{
		//see operator /=

		boost::filesystem::path path_00;
		boost::filesystem::path path_01;
		boost::filesystem::path path_02;

		path_00="./data";
		path_01="data_00.ext";
		path_02=path_00/path_01;
		assert(path_02.string()=="./data/data_00.ext");

		path_00="./data/";
		path_01="data_00.ext";
		path_02=path_00/path_01;
		assert(path_02.string()=="./data/data_00.ext");

		path_00="./data";
		path_01="/data_00.ext";
		path_02=path_00/path_01;
		assert(path_02.string()=="./data/data_00.ext");

		path_00="./data/";
		path_01="/data_00.ext";
		path_02=path_00/path_01;
		assert(path_02.string()=="./data//data_00.ext");
	}*/
	return 0;
}
