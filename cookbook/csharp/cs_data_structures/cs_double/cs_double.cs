using System;
//---------------------------------------------------------
public class List
{
	static public void Main()
	{
		double d=1.45;
		{
			Console.WriteLine( 0/d == double.NaN );
			Console.WriteLine( 0/d != double.NaN );
			Console.WriteLine( double.IsNaN(0/d) );
		}
		{
			double.IsInfinity (d);
		}
		{
			Console.WriteLine("{0}", d);
		}
	}
}
