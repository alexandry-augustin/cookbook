class base
{
	private static int	n_00;
	private int		n_01;

	public base(int n)
	{
		n_00=n;
		n_01=n;
	}
	public static int get_00()
	{
		//get_01(); //nok

		//return n_01; //nok
		return n_00;
	}
	public int get_01()
	{
		int ret;
		ret=n_00;
		ret=n_01;

		get_00();

		return ret;
	}
}
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		{
			base b=new base(5);
			assert(b.get_00()==5);
			assert(b.get_01()==5);
		}
	}
}
