#ifndef BASE_H
#define BASE_H

#include <list>

class base
{
	int		_n;
	std::list<int>	_l;
public:
	base(int n=0);
	int get_n() const;
	const std::list<int>& get_list() const;
	void set_n(int n);
	void add(int n);
	void sub(int n);
};
#endif
