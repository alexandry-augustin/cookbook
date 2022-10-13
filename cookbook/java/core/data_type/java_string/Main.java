class Base
{
	private int _n;
	public Base(int n) { _n=n; }
	public int getN() { return _n; }
	public void setN(int n)	{ _n=n; }
	public String toString() { return Integer.toString(_n); }
}
//---------------------------------------------------------
public class Main
{
	public static Base add(Base a, Base b)
	{
		return new Base(a.getN()+b.getN());
	}
	public static void main(String[] args)
	{
		{
			String str_00="abc";
			String str_01=str_00;
			str_01="123";
			assert(str_00.equals("abc"));
			assert(str_01.equals("123"));
		}
		{
			String str=new String("test");

			assert(str!="test"); //== compares references, not values
			assert(str.equals("test")); //Object.equals. can be overridden
		}
		{
			String str_00=new String("test");
			String str_01="test";

			assert((str_00+"_"+str_01).equals("test_test"));
		}
		{
			Base b=new Base(5);
			//assert(b=="5");
			System.out.println(b);
			System.out.println(add(b, b));
			System.out.println(add(new Base(5), new Base(8)));
		}
		{
			String str=String.format("%d %s", 10, "abc");
			assert(str.equals("10 abc"));
		}
	}
}
