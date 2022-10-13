#include <iostream>
#include <cassert>

static int global;

/*class IDGenerator
{
    static int s_nNextID;
 
public:
     static int GetNextID() { return s_nNextID++; }
};
 
int IDGenerator::s_nNextID = 1;
 
int main()
{
    for (int i=0; i < 5; i++)
        cout << "The next ID is: " << IDGenerator::GetNextID() << endl;
 
    return 0;
}*/

void free_fct();
static void static_free_fct(); //static limit the scope to this translation unit (.h + .cpp).

struct base_00
{
	static int fct()
	{
		int n=0;
		return n++;
	}
};

struct base_01
{
	static int m_x;
};

class base
{
	static int m_x;
public:
	//base(): m_x(0) { } //error?
	//base() { m_x=0; }  //error?
	int get() { return m_x; }
	void set(int x) { m_x=x; }
};
