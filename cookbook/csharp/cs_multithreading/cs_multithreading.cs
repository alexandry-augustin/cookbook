using System;
using System.Threading;
using System.Collections.Generic;

class Multithreading
{
	static void Worker00()
	{
		Console.WriteLine("{0}", 0);
	}
	static void Worker01(int n)
	{
		Console.WriteLine("{0}", n);
	}
	static void Main(string[] args)
	{
/*		{
//			ThreadStart job = new ThreadStart(Worker);
			Thread t= new Thread(Worker00);
			t.Start();
		}*/
		{
			HashSet<Thread> pool=new HashSet<Thread>();
			for(int i=0; i<5; ++i)
			{
				//http://www.albahari.com/threading/
				//The problem is that the i variable refers to the same memory location throughout the loop’s lifetime. Therefore, each thread calls Console.Write on a variable whose value may change as it is running!
				//The solution is to use a temporary variable
				int tmp=i;
				Thread t= new Thread(() => Worker01(tmp));
				pool.Add(t);
				t.Start();
			}
			foreach (Thread t in pool)
				t.Join();
		}
	}
}

