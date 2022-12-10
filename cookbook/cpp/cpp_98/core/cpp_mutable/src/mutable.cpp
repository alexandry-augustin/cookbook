#include <iostream>
#include <string>

//mutable break const-corretness
//example: debugging variable, caching

class base
{
	mutable int _n;
public:
	base():	_n(0) { }
	int get_n() const { return _n++; }
};

//example: caching results of expensive operation
//we don't calculate pi until someone asks for it.
//When they do, we cache the result.
//Logically the function is still const (pi isn't about to change).
class math
{
	mutable bool	_is_cached;
	mutable double	_pi;
public:
	math():	_is_cached(false) { }
	double get_pi() const
	{
		if(_is_cached==false)
		{
			/* This is an insanely slow way to calculate _pi. */
			_pi=4;
			for(long step = 3; step < 1000000000; step += 4)
				_pi+=((-4.0/(double)step) + (4.0/((double)step+2)));
			_is_cached=true;
		}
		return _pi;
	}
};

int main()
{
	{
		base b;
		b.get_n();
	}
	{
		math o;
		o.get_pi();
	}
	return 0;
}
