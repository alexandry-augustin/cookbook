#include <cstdio> //for remove()
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>

// destructor close the file automatically

//void main_()
//{
//	ofstream ofs("data");
//	if(ofs.is_open())
//	{
//		ofs<<"This is a line.\n";
//		ofs<<"This is another line.\n";
//		ofs.close();
//	}
//	else cout<<"Unable to open file";
//
//
//	string line;
//	ifstream fin("data");
//	if(fin.is_open())  //tries to open the file
//	{
//		while(!fin.eof())
//		{
//			fin.getline(fin, line);
//			if(fin.good())
//			{
//				cout<<line.c_str()<<endl;
//			}
//			else
//				cout<<"Data error"<<endl;
//		}
//	}
//	else
//		cout<<"Could not open the file"<<endl;
//	
//	fin.close();
//}

void open_modes()
{
	{
		std::fstream fs;

		assert(!fs.is_open());
	}
	{
		std::fstream fs("data"); //implicitly open the file

		assert(fs.is_open());
	}
	{
		std::ofstream ofs("temp"); //file created if it does not exist, truncated otherwise

		assert(ofs.is_open());
		assert(remove("temp")==0); //remove the file from the file system
	}
	{
		std::ifstream ifs("unknown"); //fail if file does not exist

		assert(!ifs.is_open());
		assert(ifs.fail());
		assert(!ifs.eof());
		assert(!ifs.good());
	}
	{
		//open() and close() set failbit on failure
		std::fstream fs;

		fs.open("unknown_file");
		assert(!fs.is_open());
		assert(fs.fail());
		assert(!fs.eof());
		assert(!fs.good());
	}
	{
		//is_open() indicates wether a file stream is connected to an open file.
		//shall not to be used for error checking.
		std::fstream fs;

		fs.open("data");
		assert(fs.is_open());
		assert(!fs.fail());
		assert(!fs.eof());
		assert(fs.good());

		//fails on opening an opened file
		fs.open("data");
		assert(fs.is_open());
		assert(fs.fail());
		assert(!fs.eof());
		assert(!fs.good());

		fs.close();
	}
	{
		//defaults
		std::ifstream fs_00("data", std::ios_base::in);		//==std::ifstream ifs("data");
		std::ofstream fs_01("data", std::ios_base::out);	//==std::ofstream ofs("data");
		std::fstream fs_02("data", std::ios_base::in | std::ios_base::out);//==std::fstream fs("data");
		std::fstream fs_03("data", std::ios_base::in);		//==std::fstream fs("data", std::ios_base::in);
		std::fstream fs_04("data", std::ios_base::out);		//==std::fstream fs("data", std::ios_base::out);
		std::ifstream fs_05("data", std::ios_base::out);	//==std::ifstream ifs("data", std::ios_base::in | std::ios_base::out);
		std::ofstream fs_06("data", std::ios_base::in);		//==std::ofstream ofs("data", std::ios_base::out | std::ios_base::in);
	}
}

void writting()
{
	{
		std::ofstream ofs("data");

		assert(ofs.is_open());
		for(int i=0; i<10; ++i)
			ofs<<i<<std::endl;
		ofs.close();
	}
}

void reading()
{
	{
//		std::ifstream fin("data");
//		//or ifstream fin; fin.open("data", ios::out);
//		if(!fin.is_open())  //tries to open the file
//		{
//			std::cerr<<"Could not open the file"<<std::endl;
//			return 1;
//		}
//		int n;
//		bool eof=false;
//		while(!eof)
//		{
//			fin>>n;
//			if(!fin.good())
//			{
//				std::cerr<<"data error"<<std::endl;
//				fin.close();
//				exit(1);
//			}
//			std::cout<<n<<std::endl;
//			eof=fin.eof();
//		}
//		fin.close();
	}	
	{
		std::ifstream fin("data");
		//or ifstream fin; fin.open("data", ios::out);
		assert(fin.is_open());
		std::string str;
		getline(fin, str);
		std::cout<<str<<std::endl;
		fin.close();
	}
}

void misc()
{
	{
		std::ifstream ifs;
		std::istream& is=ifs;
	}
//	{
//		std::fstream fs("data", std::ios::in | std::ios::out);
//		int n;
//
//		for(int i=0; i<5; ++i)
//		{
//			fs.seekg(i, std::ios::beg);
//			fs>>n;//can't work on \n
//			assert(fs.good());
//			std::cout<<n;
//		}
//
//		//fs.seekg(0, std::ios::end);
//		//fs>>n;
//		//std::cout<<n;
//	}
	{
		std::fstream fs("data", std::ios::in | std::ios::out);

		std::streampos p=fs.tellg(); //get current position
		//or
		//int p=fs.tellg(); //get current position
		assert(p==0);
	
		fs.seekg(p); //set current position
		assert(p==0);
	}
	{
		std::fstream fs("data", std::ios::in | std::ios::out);

		fs.seekg(6, std::ios::beg);

		// Read the next 5 characters from the file into a buffer
		//char buffer[6];
		//fs.read(buffer, 5);

		// End the buffer with a null terminating character
		//buffer[5] = 0;

		// Output the contents read from the file and close it
		//cout << buffer << endl;
				     
		fs.close();
	}
	{
		std::fstream fs;
		std::string buf("n/a");

		assert(!fs.is_open());
		std::getline(fs, buf);
		assert(buf.empty());

		fs.open("data");
		std::getline(fs, buf);
		assert(buf=="0");

		fs.close();
	}
}

int main()
{
	open_modes();
	writting();
	//reading();
	misc();

	return 0;
}
