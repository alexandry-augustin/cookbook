#include <cassert>

class base_10 { };

class base_00
{
	//Member functions of the enclosing class have no special access to members of a nested class
private:
	int _n_00;
	class base_02 { };
protected:
	int _n_01;
	class base_03: public base_10 { };
public:
	int n_02;

	class base_01
	{
	//Member functions of a nested class have no special access privileges to members of their enclosing classes.
	private:
		int _n_00;
	protected:
		int _n_01;
	public: 
		int n_02;

		void f_00()
		{
			base_02 b;
		}
	};
};

//https://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fcplr061.htm
class A
{
	int x;
	class B { };
	class C
	{
		// The compiler cannot allow the following
		// declaration because A::B is private:
		//   B b;

		int y;
		void f(A* p, int i)
		{
			// The compiler cannot allow the following
			// statement because A::x is private:
			//   p->x = i;

		}
	};
	void g(C* p)
	{
		// The compiler cannot allow the following
		// statement because C::y is private:
		//   int z = p->y;
	}
};

int main()
{
	{
		base_00 b_00;
		base_00::base_01 b_01;

		b_01.n_02=5;
		assert(b_01.n_02==5);
	}
	return 0;
}
