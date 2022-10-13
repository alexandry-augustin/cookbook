final class Base_00 //cannot be subclassed
{
}
class Base_01 //extends Base_00 //nok
{
}
class Base_02
{
	public final void fct() //cannot be overridden or hidden by subclasses
	{
	}
}
class Base_03 extends Base_02
{
	//@Override public final void fct() { } //nok
}
class Base_04
{
	public final int	_n_00=0;
	public final int	_n_01; //"blank final"
	public final int	_n_02; //"blank final"
	public int		_n_03;

	Base_04(int n)
	{
		_n_01=0;
		_n_02=n;
		_n_03=n;
	}
	public void setN(int n)
	{
		//_n_00=n; //nok
		//_n_01=n; //nok
		//_n_02=n; //nok
		_n_03=n;
	}
}
public class Main
{
	public static void main(String[] args)
	{
		{
			//unlike the value of a constant,
			//the value of a final variable is not necessarily known at compile time
			final int n=0;
			//n=5; //nok
			//---------------------------------
			final int m; //"blank final"
			m=0;
			//m=5; //nok
			//---------------------------------
		}
		{
			final Base_01 base_01=new Base_01();
			//---------------------------------
			final Base_04 base_02=new Base_04(5);
			//base_02=new Base_04(5); //nok
			//base_02._n_00=6; //nok
			//base_02._n_01=6; //nok
			//base_02._n_02=6; //nok
			base_02._n_03=6;
		}
	}
}
