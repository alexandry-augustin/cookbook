public class Main
{
	public static void main(String[] args)
	{
		{
			Object o=null;
			assert(o==null);
			o=new Object();
			assert(o!=null);
		}
	}
}
