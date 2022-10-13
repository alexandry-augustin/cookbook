#ifndef BASE_00_h
#define BASE_00_h

class base
{
	int 	_n;
public:
	base(int n): _n(n) { /*std::cout<<"[base::base] ["<<_n<<"]"<<std::endl;*/ }
	~base() { /*std::cout<<"[base::~base] ["<<_n<<"]"<<std::endl;*/ }
	int get_n() const { return _n; }
	int set_n(int n) { _n=n; }
};

#endif
