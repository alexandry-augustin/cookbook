using System;
using System.Linq;
using System.Collections.Generic;
//---------------------------------------------------------
/*public static class Globals
{
    public static String s_Name = "Mike"; // Modifiable in Code
    public const Int32 VALUE = 10; // Unmodifiable
}*/
//---------------------------------------------------------
public class Person
{ 
	internal int id;
	internal string car;
}
//---------------------------------------------------------
class Pet
{
	public string Name { get; set; }
	public int Age { get; set; }
}
//---------------------------------------------------------
public class Linq_
{
	private static bool IsEven(int value)
	{
		return value%2==0;
	}
	private static void GroupBy()
	{
		List<Person> l = new List<Person>{ 
			new Person { id=1, car="Ferrari" },
			new Person { id=1, car="BMW" },
			new Person { id=2, car="Audi" }
		};
		List<Pet> pets = new List<Pet>{ 
			new Pet { Name="Barley",	Age=8 },
			new Pet { Name="Boots",		Age=4 },
			new Pet { Name="Whiskers",	Age=1 },
			new Pet { Name="Daisy",		Age=4 }
		};
		//-----------------------------------------
		{
			List<Tuple<int, int>> data = new List<Tuple<int, int>> ();
			data.Add (new Tuple<int, int>(0, 8));
			data.Add (new Tuple<int, int>(0, 9));
			data.Add (new Tuple<int, int>(1, 8));
			data.Add (new Tuple<int, int>(1, 7));

			foreach (var e in data.GroupBy (e => e.Item1))
			{
				Console.Write ("[{0}]: ", e.Key);
				foreach (var e1 in e)
					Console.Write ("{0} ", e1.Item2);
				Console.Write ("\n");
			}
			//Result:
			// [0]: 8 9 
			// [1]: 8 7

			foreach (var e in data.GroupBy (e => e.Item2))
			{
				Console.Write ("[{0}]: ", e.Key);
				foreach (var e1 in e)
					Console.Write ("{0} ", e1.Item1);
				Console.Write ("\n");
			}
			//Result:
			// [8]: 0 1 
			// [9]: 0 
			// [7]: 1 
		}
		//transforms a collection into groups
//		{
//			//http://www.dotnetperls.com/groupby
//			int[] array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//			var result = array.GroupBy(a => IsEven(a)); //group by even numbers
//			foreach (var group in result)
//			{
//				if(group.Key==true)
//					System.Console.WriteLine ("even numbers: {0}",  string.Join(" ", group));
//			}
//		}
		{

			// Group the pets using Age as the key value 
			// and selecting only the pet's Name for each value.
			/*IEnumerable<IGrouping<int, string>> query = pets.GroupBy(pet => pet.Age, pet => pet.Name);
			foreach (IGrouping<int, string> petGroup in query)
			{
				Console.WriteLine(petGroup.Key);
				System.Console.WriteLine (string.Join(" ", petGroup));
			}*/

			/*var res = pets.GroupBy(pet => pet.Age, pet => pet.Name);
			foreach (var petGroup in res)
			{
				Console.WriteLine(petGroup.Key);
				System.Console.WriteLine (string.Join(" ", petGroup));
			}*/

			{
				var res = pets.GroupBy(pet => pet.Age);
				//System.Console.WriteLine (res);
				foreach (var petGroup in res)
				{
					Console.Write("{0}: ", petGroup.Key);
					//System.Console.WriteLine (petGroup);
					foreach(var pet in petGroup)
						System.Console.Write("{0}, ", pet.Name);
					Console.Write("\n");
				}
			}
			{
				var res = pets.GroupBy(pet => pet.Age).ToArray(); //array of unique pet.Age
				foreach (var petGroup in res)
					System.Console.Write("{0} ", petGroup.Key);
			}
		}
		{
//			//http://stackoverflow.com/questions/7325278/group-by-in-linq
//			var res=l.GroupBy(p => p.id
//				, p => p.car
//                               //, (key, g) => new { 
//                               //                  id = key, 
//                               //                  car = g.ToList() 
//                               //                 }
//                              );
//			foreach(var group in res)
//			{
//				Console.WriteLine(group.Key);
//				System.Console.WriteLine (string.Join(" ", group));
//			}
		}
	}
	private static void Select()
	{
		List<Person> l = new List<Person>{ 
			new Person { id=1, car="Ferrari" },
			new Person { id=1, car="BMW" },
			new Person { id=2, car="Audi" }
		};
		//-----------------------------------------
		{
			int[] a=new int[5] {0, 1, 2, 3, 4};
			var b=a.Select(i => i*i).ToArray(); //equivalent to foreach()
			for(int i=0; i<b.Length; i++)
				Console.WriteLine(b[i]);
			//0 1 4 9 16
		}
		{
			var res = l.Select(i => i.car).ToList();
			foreach(var i in res)
				Console.WriteLine(i);
		}
		{
			List<string> li = new List<string>();
			li.Add("\t0");
			li.Add("\t1");
			li.Add("\t2");

			List<int> ret=li.Select(int.Parse).ToList();
			foreach(var i in ret)
				Console.WriteLine(i);
		}
	}
	private static void Distinct()
	{
		List<Person> l = new List<Person>{ 
			new Person { id=1, car="Ferrari" },
			new Person { id=1, car="Ferrari" },
			new Person { id=2, car="Audi" }
		};
		//-----------------------------------------
		{
			var res = l.Select(i => i.car).Distinct().ToList();
			foreach(var i in res)
				Console.WriteLine(i);
		}
	}
	public static void Zip()
	{
		{
			//dot product
			//http://stackoverflow.com/questions/3992363/sum-of-products-of-two-arrays-dotproduct
			int[] a = new int[3]{0,1,2};
			int[] b = new int[3]{0,1,2};

			//Note that Zip will not fail like it should when the arrays of unequal length, so you probably need to validate the input:
			if(a.Length != b.Length)
				throw new ArgumentException("...");

			int dotProduct = a.Zip(b, (d1, d2) => d1 * d2).Sum();
			Console.WriteLine(dotProduct);
		}
	}
	private static void Misc()
	{
		List<Person> l = new List<Person>{ 
			new Person { id=1, car="Ferrari" },
			new Person { id=1, car="BMW" },
			new Person { id=2, car="Audi" }
		};
		List<Pet> pets = new List<Pet>{ 
			new Pet { Name="Barley", Age=8 },
			new Pet { Name="Boots", Age=4 },
			new Pet { Name="Whiskers", Age=1 },
			new Pet { Name="Daisy", Age=4 }
		};
		//-----------------------------------------
		{
			//Where
			int[] a=new int[5] {0, 1, 2, 3, 4};
			var b=a.Where(i => i>2).ToArray();
//			for(int i=0; i<b.Length; i++)
//				Console.WriteLine(b[i]);
		}
		{
			//Any
			int[] a={3, 3, 3};
			bool isEven=a.Any(i => i % 2==0);
			bool isOdd=a.Any(i => i % 2!=0);
			bool areAbove2=a.All(i => i > 2);
			System.Console.WriteLine (isEven);
			System.Console.WriteLine (isOdd);
			System.Console.WriteLine (areAbove2);
		}
		{
			//Concat
			int[] a=new int[3] {0, 1, 2};
			a = a.Concat(a).ToArray();
			Console.WriteLine(String.Join(" ", a));
		}
		{
			//Distinct
			int[] a=new int[4] {0, 1, 2, 2};
			var res=a.Distinct();
			System.Console.WriteLine (string.Join(" ", res));
		}
		{
			//Sum
			Dictionary<string, int> d=new Dictionary<string, int>();
			d["a"]=10;
			d["b"]=15;
			System.Console.WriteLine (d.Sum(i => i.Value));
		}
		{
			//slicing arrays
			int[] arr = new int[] { 2,3,4,5,6 };
			int[] slice = arr.Skip(2).Take(2).ToArray();
			foreach(int i in slice)
				System.Console.Write("{0} ", i);
		}
	}
	static public void Main()
	{
		GroupBy();
		//Select();
		//Distinct();
		//Zip();
		//Misc();
	}
}
