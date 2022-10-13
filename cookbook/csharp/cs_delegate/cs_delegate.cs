//Delegates are like C++ function pointers but are type safe.
using System;

namespace delegate_
{
	class MainClass
	{
		public delegate void inner();

		public static void inner1()
		{
			Console.WriteLine("inner1");
		}
		public static void inner2()
		{
			Console.WriteLine("inner2");
		}
		public static void outer(inner func)
		{
			Console.WriteLine("before");
			func();
			Console.WriteLine("after");
		}
		public static void Main (string[] args)
		{
			outer (inner2);
		}
	}
}
