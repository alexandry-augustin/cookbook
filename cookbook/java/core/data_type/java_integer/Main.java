public class Main
{
	public static void main(String[] args)
	{
		{
			Integer n=new Integer(0);
			int m=0;

			assert(n.intValue()==m);
			n=Integer.valueOf(m);
		}
	}
}
