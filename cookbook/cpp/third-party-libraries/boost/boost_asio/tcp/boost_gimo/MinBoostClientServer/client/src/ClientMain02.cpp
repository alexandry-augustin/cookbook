#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

int main()
{
	try
	{
		const char* host="127.0.0.1";// or "localhost";
		const int port=50013;
		boost::asio::io_service			io_service;
		boost::asio::ip::tcp::endpoint		endpoint(boost::asio::ip::address::from_string(host), port);
		boost::asio::ip::tcp::socket		socket(io_service);
		boost::system::error_code 		error=boost::asio::error::host_not_found;
		socket.close();
		
		socket.connect(endpoint, error);
		if(error) //no socket connection succeeded
			throw boost::system::system_error(error);
		
		//we have a socket connection to the server, we plan to read from it till we get an EOF.
		while(1)
		{
			boost::array<char, 4> buf;
			//put the retrieved data in the buffer, and iterate the reading until the end. 
			//The passed chunck of memory is converted to an asio::buffer object - using a boost::array we spare ourself the bore of passing also the size of the 				//memory block, the asio::buffer is smart enough to get it directly from boost::array.
			size_t len = socket.read_some(boost::asio::buffer(buf), error); 

			if(error==boost::asio::error::eof) 	//check the error set by read_some().
				break; 				//Connection closed cleanly by peer.
			else
				if(error)
					throw boost::system::system_error(error);

			std::cout<<"[!]"; // show the actual joins in the data communication.
			std::cout.write(buf.data(), len); // output the chunk of data currently read from the socket.
		}
	}
	catch(std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
}
