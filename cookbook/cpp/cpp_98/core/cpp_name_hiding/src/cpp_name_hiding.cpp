struct base_00
{
	virtual void f_00(int n) { }
	virtual void f_00(int* n) { }
};

struct base_01: public base_00
{
	/*virtual*/ void f_00(int* n) { }

	// void f_00(int n) won't be found by compiler.
	//the name lookup will stop looking for other names as soon as it finds a single name in one of your base classes. 
	//using base_00::f_00; //solution
};

int main()
{
	{
		base_01 b;
		b.f_00(6); //compile-time error
	}
	return 0;
}
