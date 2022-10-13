#include <iostream>
#include <sstream>
#include <cassert>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//---------------------------------------------------------
int main()
{
	{
		boost::asio::streambuf				streambuf;
		boost::asio::streambuf::mutable_buffers_type	mutable_buffers(streambuf.prepare(10));
		boost::asio::mutable_buffer			mutable_buffer;
		std::ostringstream				oss;
		//-----------------------------------------
		mutable_buffer=boost::asio::buffer(mutable_buffers);
		oss<<&streambuf;
		//-----------------------------------------
		streambuf.consume(streambuf.size());
		assert(streambuf.size()==0);
	}
	return 0;
}
