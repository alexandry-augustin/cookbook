//subclasses of Throwable: includes Exception and Error
//---------------------------------------------------------
//public class Throwable extends Object implements Serializable
//{
//	String getMessage()
//	String getLocalizedMessage()
//	String toString()
//	void printStackTrace()
//	...
//}
//---------------------------------------------------------
class Base_00 extends Exception
{
	public Base_00(String message)
	{
		super(message);
	}
}
//---------------------------------------------------------
class Base_01 extends Throwable
{
	public Base_01(String message)
	{
		super(message);
	}
}
//---------------------------------------------------------
class Base_02 extends Base_01
{
	public Base_02(String message)
	{
		super(message);
	}
}
//---------------------------------------------------------
public class Main
{
	private void f_00() throws Base_00
	{
	}
	private void f_01() throws Base_00
	{
		throw new Base_00("exception");
	}
	private void f_02() throws Base_00
	{
		f_01();	
	}
	private void f_03() throws Base_00
	{
		f_00();	
	}
	private void f_04(boolean b) throws Base_00, Base_01 //mandatory
	{
		if(b)
			throw new Base_00("exception");
		else
			throw new Base_01("exception");
	}
	public static void main(String[] args)
	{
		assert(new Exception() instanceof Throwable);
		//-----------------------------------------
		try
		{
			throw new Throwable("exception");
		}
		catch(Throwable e)
		{
			assert(e.toString().equals("java.lang.Throwable: exception"));
		}
		//-----------------------------------------
		try
		{
			throw new Exception("exception");
		}
		catch(Exception e)
		{
			assert(e.toString().equals("java.lang.Exception: exception"));
		}
		//-----------------------------------------
		try
		{
			throw new Base_00("exception");
		}
		catch(Base_00 e)
		{
			assert(e.toString().equals("Base_00: exception"));
		}
		//-----------------------------------------
		//try
		//{
		//	throw new Integer(0);
		//}
		//catch(Integer e)
		//{
		//	System.out.println(e);
		//}
		//-----------------------------------------
		//compile error
		/*try
		{
			throw new Base_01("exception");
		}
		catch(Base_00 e)
		{
			System.out.println(e);
		}*/
		//-----------------------------------------
		try
		{
			int n=9/0;
		}
		catch(Exception e)
		{
			assert(e.toString().equals("java.lang.ArithmeticException: / by zero"));
		}
		//-----------------------------------------
		try
		{
			double n=9/0.0;
			//System.out.println(n);
			assert(Double.isInfinite(n));
		}
		catch(Exception e)
		{
			assert(false);
		}
	}
}
