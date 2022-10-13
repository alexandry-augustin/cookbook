interface IBase
{
	int getN();
}
//---------------------------------------------------------
class Base_00 implements IBase
{
	private int _n;
	
	public Base_00(int n)
	{
		_n=n;
	}
	public int getN()
	{
		return _n;
	}
	public void setN(int n)
	{
		_n=n;
	}
}
//---------------------------------------------------------
class Base_01
{
	public int n;
	public final int final_n;

	public Base_01(int n)
	{
		this.n=n;
		this.final_n=n;
	}
}
//---------------------------------------------------------
class Math
{
	public static Base_00 add(IBase a, IBase b)
	{
		return new Base_00(a.getN()+b.getN());
	}
	public static Base_00 add(Base_00 a, Base_00 b)
	{
		return new Base_00(a.getN()+b.getN());
	}
}
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		{
			IBase b=new IBase()
				{
					@Override
					public int getN()
					{
						return 0;
					}
				};
			assert(b.getN()==0);
		}
		{
			Base_00 b=Math.add(new IBase()
				{
					@Override
					public int getN()
					{
						return 9;
					}
				}, new Base_00(8));
		}
		{
			final int n=5;
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return n;
					}
				}.getN()==5);
		}
		{
			final Base_01 b=new Base_01(5);
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return b.n;
					}
				}.getN()==5);
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return b.final_n;
					}
				}.getN()==5);
			b.n=6;
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return b.n;
					}
				}.getN()==6);
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return b.final_n;
					}
				}.getN()==5);
		}
		{
/*			final Base_01 b_00=new Base_01(5);
			IBase b_01=new IBase()
				{
					@Override
					public int getN()
					{
						return b_00.n;
					}
				};
			assert(b_01.getN()==5);
			b.n=6;
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return b.n;
					}
				}.getN()==6);
			assert(new IBase()
				{
					@Override
					public int getN()
					{
						return b.final_n;
					}
				}.getN()==5);*/
		}
	}
}
