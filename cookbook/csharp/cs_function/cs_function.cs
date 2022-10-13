//Delegates are like C++ function pointers but are type safe.
using System;

namespace function_
{
	class MainClass
	{
		public static void f(out int n)
		{
			n=1;
		}
		public static void Main (string[] args)
		{
			int n=0;
			f(out n);
			Console.WriteLine(n);
		}
	}
}
