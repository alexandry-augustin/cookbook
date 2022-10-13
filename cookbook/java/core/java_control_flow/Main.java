public class Main
{
	private static void testFor()
	{
		int a[]={ 0, 1, 2, 3 };
		{
			for(int i=0; i<a.length; ++i)
				assert(a[i]==i);
		}
		{
			//foreach syntax (since java SE5)
			int n=0;
			for(int i: a)
			{
				assert(a[i]==n++);
			}
		}
	}
	private static void testMisc()
	{
		{
			int i=0;
			while(i<5)
				++i;
		}
		{
			do
				System.out.print("");
			while(false);
		}
	}
	private static void testSwitch()
	{
		{
			String str="abc";

			//(since java SE 7)
			switch(str)
			{
			case "abc":
				break;
			default:
				assert(false);
			}
		}
		{
			int n=0;

			switch(n)
			{
			case 0:
				break;
			default:
				assert(false);
			}
		}
	}
	public static void main(String[] args)
	{
		testFor();
		testSwitch();
		testMisc();
	}
}
