//import my_space; <=> 'using namespace my_space;' in c++
//import base.Base;
//import base.*;
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		base.Base b=new base.Base(0);
		//Base b=new Base(0);

		assert(b.get()==0);
	}
}
