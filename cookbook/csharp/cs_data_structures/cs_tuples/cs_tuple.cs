using System;

public class Tuple
{
	
	static Tuple<int, int> f()
	{
		return new Tuple<int, int>(1, 2);
	}
	static public void Main()
	{
		
		var t= f();
		int a = t.Item1;
		int b = t.Item2;
		Console.WriteLine("{0} {1}", a, b);
	}
}
