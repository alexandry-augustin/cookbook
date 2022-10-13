class Base_00
{
	private int _n;
	public class Base_01
	{
		private int __m;
		public Base_01(int m) { __m=m; }
		public int get_m() { return __m;	}
		public void set_m(int m) { __m=m; }
		public int get_n()
		{
			//return _n;
			//or
			return Base_00.this._n;
		}
		public void set_n(int n) { _n=n; }
	}
	public class Base_02
	{
		private Base_01 __b_01;
	}
	Base_01 _b_01;
	public Base_00(int n)
	{
		_n=n;
		_b_01=new Base_01(n);
	}
	public int get_n() { return _n; }
	public void set_n(int n) { _n=n; }
	public Base_01 get_base_01() { return _b_01; }
	public void set_base_01(Base_01 b) { _b_01=b; }
}
//---------------------------------------------------------
//it’s not possible to create an object of the inner class unless you already have an object of the outer class.
//nested class = static inner class
public class Main
{
	public static void main(String[] args)
	{
		{
			Base_00 b_00=new Base_00(5);
			Base_00.Base_01 b_01=b_00.get_base_01();
			assert(b_00.get_n()==b_01.get_m());
		}
		{
			Base_00 b_00=new Base_00(5);
			Base_00.Base_01 b_01=b_00.new Base_01(6);
			assert(b_00.get_n()!=b_01.get_m());
		}
		{
			Base_00 b_00=new Base_00(5);
			b_00.get_base_01().set_n(2);
			assert(b_00.get_n()==2);
		}
	}
}
