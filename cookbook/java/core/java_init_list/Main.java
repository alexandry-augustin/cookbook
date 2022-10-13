class base
{
	private String _str_00=new String("abc");
	private String _str_01=_str_00;
	base()
	{
		assert(_str_01.equals("abc"));
	}
}
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		base b=new base();
	}
}
