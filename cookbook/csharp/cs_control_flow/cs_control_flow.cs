using System;

class ForEachTest
{
    static void Main(string[] args)
    {
	{
		int[] fibarray = new int[] { 0, 1, 1, 2, 3, 5, 8, 13 };
		foreach (int element in fibarray)
		{
		    System.Console.WriteLine(element);
		}
		System.Console.WriteLine();


		// Compare the previous loop to a similar for loop.
		for (int i = 0; i < fibarray.Length; i++)
		{
		    System.Console.WriteLine(fibarray[i]);
		}
		System.Console.WriteLine();

		foreach(int i in Enumerable.Range(1, 3))
		{
			Console.WriteLine(i);
		}

		// You can maintain a count of the elements in the collection.
		int count = 0;
		foreach (int element in fibarray)
		{
		    count += 1;
		    System.Console.WriteLine("Element #{0}: {1}", count, element);
		}
		System.Console.WriteLine("Number of elements in the array: {0}", count);
	}
	{
		string str="aaa";
		switch (str)
		{
		    case "aaa":
			System.Console.WriteLine("{0}", str);
			break;
		    case "bbb":
			System.Console.WriteLine("{0}", str);
			break;
		    default:
			System.Console.WriteLine("{0}", str);
			break;
		}
	}
    } 
}
