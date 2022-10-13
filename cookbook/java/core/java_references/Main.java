class base
{
	private int _n;
	public base(int n) { _n=n; }
	public int get() { return _n; }
	public void set(int n) { _n=n; }
}
//---------------------------------------------------------
public class Main
{
	private static void f_00(int n)
	{
		++n;
	}
	private static void f_01(String str)
	{
		str+="_changed";
	}
	private static void f_02(base b)
	{
		b.set(0);
	}
	private static void f_03(base b)
	{
		b=new base(0);
	}
	public static void main(String[] args) 
	{
		{
			String s; //un-initialized reference
			//assert(s==null);
			s=new String("test");
		}
		{
			int n=5;

			f_00(n);
			assert(n==5);
		}
		{
			String str=new String("test");

			f_01(str);
			assert(str.equals("test"));
		}
		{
			base b=new base(5);

			f_03(b);
			assert(b.get()==5);
		}
		{
			base b=new base(5);

			assert(b.get()==5);
			f_02(b);
			assert(b.get()==0);
		}
	}
}
