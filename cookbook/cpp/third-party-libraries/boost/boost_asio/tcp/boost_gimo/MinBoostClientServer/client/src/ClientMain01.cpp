#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

int _main()
{
	try
	{
		const char* host="127.0.0.1";// or "localhost";
		const char* port="50013";

		boost::asio::io_service io_service;

		boost::asio::ip::tcp::resolver resolver(io_service); //provide a connection to the server
		boost::asio::ip::tcp::resolver::query query(host, port); //to actually get the connection, we create a resolver::query object
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator=resolver.resolve(query); //iterator to the resulting connections
		boost::asio::ip::tcp::resolver::iterator end; //iterator to terminate a loop (calling the default ctor).

		boost::asio::ip::tcp::socket socket(io_service);
		boost::system::error_code error=boost::asio::error::host_not_found;
		//loop on all the endpoints retrieved by our query on the resolver until we find a working one (not giving an error when 			
		//we use it as an endpoint for our socket).
		//The code works smoothly from the second iteration on, the issue is the first one: since there is no previous 		
		//iteration, we should assume it, initializing error as it was a bad endpoint, and closing the socket in any case, just for homogeneity.
		while(error && endpoint_iterator!=end)
		{
			socket.close();
			socket.connect(*endpoint_iterator++, error);
		}
		if(error) //no socket connection succeeded
			throw boost::system::system_error(error);

		while(1) //we have a socket connection to the server, we plan to read from it till we get an EOF.
		{
			boost::array<char, 4> buf;
			//put the retrieved data in the buffer, and iterate the reading until the end. 
			//The passed chunck of memory is converted to an asio::buffer object - using a boost::array we spare ourself the bore of passing also the size of the 				//memory block, the asio::buffer is smart enough to get it directly from boost::array.
			size_t len = socket.read_some(boost::asio::buffer(buf), error); 

			if(error == boost::asio::error::eof) 	//check the error set by read_some().
				break; 				// Connection closed cleanly by peer.
			else if(error)
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
