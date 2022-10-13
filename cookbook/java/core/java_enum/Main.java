enum base_00
{
	A,
	B
}
public class Main
{
	public static void main(String[] args) 
	{
		{
			base_00 b=base_00.A;

			assert(b.toString()=="A");
			assert(b.ordinal()==2);
		}
		{
			base_00 b[]=base_00.values();
		}
	}
}
