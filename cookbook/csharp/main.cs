using System;

public class Sandbox
{
	static public void Main()
	{
		Console.WriteLine("Hello Mono World");
		//Range r=new Enumerable.Range(3);

		foreach(string str in new string[2]{"abc","123"})
		{
			Console.WriteLine(str);
		}
	}
}
