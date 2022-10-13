#include <iostream>
#include <sstream>
#include <cassert>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//---------------------------------------------------------
// boost::asio::buffer is a bench of overloaded functions that adapt various containers
// to ConstBufferSequence or MutableBufferSequence concepts.
//---------------------------------------------------------
void const_buffer()
{
	{
		char a[]={ 'a', 'b', 'c' };
		boost::asio::const_buffer b_00=boost::asio::buffer(a, 3); //max size

		std::size_t size_00=boost::asio::buffer_size(b_00);
		assert(size_00==3);

		const char* b=boost::asio::buffer_cast<const char*>(b_00);
		assert(b[0]==a[0]);
		assert(b[1]==a[1]);
		assert(b[2]==a[2]);

		a[1]='z';
		assert(b[1]==a[1]); //does not own the underlying data

		b[2]=='x';
		assert(b[2]==a[2]); //does not own the underlying data
	}
	{
		std::string str("abc");
		boost::asio::const_buffer b(boost::asio::buffer(str));

		//char const * data=boost::asio::buffer_cast<char const *>(const_buffer);
		const char*	data=boost::asio::buffer_cast<const char*>(b);
	}
}
//---------------------------------------------------------
void mutable_buffer()
{
	{
		char a[]={ 'a', 'b', 'c' };
		boost::asio::mutable_buffer b_00=boost::asio::buffer(a, 3);

		char* b=boost::asio::buffer_cast<char*>(b_00);
		assert(b[0]==a[0]);
		assert(b[1]==a[1]);
		assert(b[2]==a[2]);
	}
	{
		boost::array<char, 3> 		a={{ 'a', 'b', 'c' }}; //{{ }} corrects gcc bug #53119
		boost::asio::mutable_buffer	b(boost::asio::buffer(a, 2)); 
	
		char* data=boost::asio::buffer_cast<char*>(b);
	}
}
//---------------------------------------------------------
int main()
{
	const_buffer();
	mutable_buffer();
	return 0;
}
