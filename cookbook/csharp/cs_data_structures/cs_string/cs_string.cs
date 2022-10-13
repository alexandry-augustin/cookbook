using System;

public class String
{
	static public void Main()
	{
		{
			string a = "hello";
			string b = "h";
			b += "ello";
			Console.WriteLine(a == b);
			Console.WriteLine((object)a == (object)b);
		}
		{
			string str = "{0}123";
    			str=string.Format(str, "abc");
			Console.WriteLine(str);
		}
		{
			int[] a= {0, 1, 2};
			string str = string.Join(",", a);
			Console.WriteLine(str);
		}
	}
}
