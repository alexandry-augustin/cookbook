using System;

delegate int f(int i);

public class Lambda
{
	static public void Main()
	{
		{
			f f_00 = x => x * x;
			int j = f_00(5);
		}
	}
}
