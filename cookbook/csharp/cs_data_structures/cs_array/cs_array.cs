using System;
using System.Linq;
using System.Collections.Generic;
//---------------------------------------------------------
public class Array
{
	//http://stackoverflow.com/questions/5383937/array-data-normalization
	private static double[] Normalise(IEnumerable<double> data, double min, double max)
	{
	    double dataMax = data.Max();
	    double dataMin = data.Min();
	    double range = dataMax - dataMin;

	    return data
		.Select(d => (d - dataMin) / range)
		.Select(n => (double)((1 - n) * min + n * max))
		.ToArray<double>();
	}
	//-------------------------------------------------
	static public void Main()
	{
		{
			//System.Array
			int i=10;
			int[] a=new int[i];
			System.Console.WriteLine (a.Length);
		}
		{
			//System.Array
			//int[] a=new int[] {0, 1, 2};
			//or
			int[] a= {0, 1, 2};
		}
		{
			//Sum()
			int[] a= {0, 1, 2};
			System.Console.WriteLine (a.Sum());
		}
		{
			//multidimensional array
			int[,] a=new int [3,2];
			System.Console.WriteLine ("{0}", a.Length); //6
			System.Console.WriteLine (a.GetLength(0)); //3
			System.Console.WriteLine (a.GetLength(1)); //2
		}
		{
			//multidimensional array
			//int[,] a= new int[2,3] { {1, 0}, {3, 6}, {9, 12} }; //error?
			//or
			int[,] a= new int[,] { {1, 0}, {3, 6}, {9, 12} };
			//a[1].Sum();
		}
		{
			//array-of-array (jagged)
			int[][] a=new int[5][];
			for (int j = 0; j < 2; j++) 
			{
				a[j] = new int[4];
			}
		}
		{
			//mix rectangular and jagged arrays
			int[][,,][,] numbers;
		}
		{
			bool[] a={true, false};
			System.Console.WriteLine (a[false?0:1]);
		}
		{
//			int[] a={0, 0, 0};
//			System.Console.WriteLine (a.EqualsAll(0));
		}
		{
			//normalise
			double[] a={0.0, 5, 8};
			double[] res=Normalise(a, 1, 2);
			for (int j = 0; j < 3; j++) 
				System.Console.WriteLine (res[j]);
		}
		{
			//IndexOf()
			//The result of IndexOf is -1 when the value is not found.
			int[] a= {7, 8, 9};
//			System.Console.WriteLine (Array.IndexOf(a, 8));
		}
		{
			//init with repeated elements
			int[] a = Enumerable.Repeat(1, 3).ToArray(); //[1 1 1]
			for (int j = 0; j < a.Length; j++) 
				System.Console.Write ("{0} ", a[j]);
			System.Console.Write ("\n");
		}
		{
			//concat with repeated elements
			int[] a = new int[] {1, 2, 3};
			List<int> tmp=new List<int>();
			for (int j = 0; j < a.Length; j++) 
			{
				List<int> sub=Enumerable.Repeat(a[j], 3).ToList();
				tmp.AddRange(sub);

			}
			int[] b=tmp.ToArray();
			for (int j = 0; j < b.Length; j++) 
				System.Console.Write ("{0} ", b[j]);
			System.Console.Write ("\n");
		}
	}
}
