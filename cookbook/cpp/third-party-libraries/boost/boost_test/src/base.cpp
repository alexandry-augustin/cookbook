#include "base.h"
base::base(int n): _n(n)
{
	for(int i=0; i<5; ++i)
		_l.push_back(_n);
}
int base::get_n() const
{
	return _n;
}
void base::set_n(int n)
{
	_n=n;
}
void base::add(int n)
{
	_n+=n;
}
void base::sub(int n)
{
	_n-=n;
}
const std::list<int>& base::get_list() const
{
	return _l;
}
