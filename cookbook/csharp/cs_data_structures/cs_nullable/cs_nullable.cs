using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
//---------------------------------------------------------
public class Base
{ 
	public int? n
	{
		get;
		set;
	}
}
//---------------------------------------------------------
public class List
{
	public static int? f_00(int? n)
	{
		return n;
	}
	public static void Main()
	{
		{
			int? n;
			//Console.WriteLine(n);
		}
		{
			int? n=5;
			n=null;
			n=f_00(n);
		}
		{
			//http://stackoverflow.com/questions/29153832/what-is-the-default-value-of-the-nullable-type-int-including-question-mark
			Base b=new Base();
			Debug.Assert(b.n==null); //default: null
			Console.WriteLine("test: {0:0.0}", b.n);
		}
		{
			int[] a=null;
			Debug.Assert(a==null); //default: null
		}
	}
}

