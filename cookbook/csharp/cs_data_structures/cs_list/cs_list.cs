using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
//---------------------------------------------------------
public class Base
{ 
	public int id;
}
//---------------------------------------------------------
public class List
{
	static public void f_00(List<int> l)
	{
		l[0]=-1;
//		l.Remove(2);
	}
	static public void Main()
	{
		{
			//Concat
			List<Base> l = new List<Base>{ 
				new Base {id=1},
				new Base {id=2},
				new Base {id=3}
			};
			//System.Console.WriteLine (string.Join(" ", l));

			l=l.Concat(l).ToList();
			Base[] a= {
				new Base{id=4},
				new Base{id=5},
				new Base{id=6},
			};
			l=l.Concat(a).ToList();

			foreach(Base b in l)
				System.Console.WriteLine (b.id);
		}
		{
			List<int> l = new List<int>();
			l.Add(0);
			l.Add(1);
			l.Add(2);

			Debug.Assert(l.Count==3);
			Debug.Assert(l.Last()==2);
			Debug.Assert(l.Contains(1));

			// Insert a new item at position 2.
			l.Insert(2, 0);
			Debug.Assert(l[2]==0);

			l.RemoveAt(2);

	//		l.Remove(0); //remove the first element found?

			foreach(int n in l)
				Console.WriteLine(n);

			l.Clear();
			Debug.Assert(l.Count==0);

	//		.TrimExcess();
		}
		{
			List<int> l = new List<int>();
			l.Add(0);
			l.Add(1);
			l.Add(2);
			l.Add(1);
			l.Add(0);
			
			int argmax=l.IndexOf(l.Max());
			Console.WriteLine(argmax);
		}
		{
			List<int> l = new List<int>();
			l.Add(0);
			l.Add(1);
			l.Add(2);

			f_00(l);
			Debug.Assert(l[0]==-1);
			System.Console.WriteLine (string.Join(" ", l.ToArray()));
		}
		{
			//append a list to existing list
			List<int> l_00 = new List<int>() {0, 1, 2} ;
			List<int> l_01 = new List<int>() {3, 2, 5} ;
			l_00.AddRange(l_01);
			System.Console.WriteLine (string.Join(" ", l_00.ToArray()));
		}
	}
}
