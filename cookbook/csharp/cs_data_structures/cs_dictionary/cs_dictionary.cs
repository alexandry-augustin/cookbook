using System;
using System.Collections.Generic;
using System.Linq; //ElementAt

public class Dictionary_
{
	//http://stackoverflow.com/questions/1028136/random-entry-from-dictionary
	static public IEnumerable<TValue> RandomValues<TKey, TValue>(IDictionary<TKey, TValue> dict)
	{
		Random rand = new Random();
		List<TValue> values = Enumerable.ToList(dict.Values);
		int size = dict.Count;
		while(true)
		{
			yield return values[rand.Next(size)];
		}
	}
	static public void Main()
	{
		{
			Dictionary<string, int> dic=new Dictionary<string, int>();
			dic["zero"]=0;
			dic["one"]=1;
			dic["two"]=2;

			foreach(KeyValuePair<string, int> e in dic)
			{
			    // do something with e.Value or e.Key
			}
		}
		{
			Dictionary<string, int> dic=new Dictionary<string, int>();
			dic["zero"]=0;
			dic["one"]=1;
			dic["two"]=2;

			List<string> keys = new List<string>(dic.Keys);
			List<string> keys2 = dic.Keys.ToList();
			List<String> keys3 = dic.Keys.ToList();
		}
		{
			// check if key exist
			Dictionary<string, int> dic=new Dictionary<string, int>();
			dic["zero"]=0;
			dic["one"]=1;
			dic["two"]=2;

			string key="zero";
			if(dic.ContainsKey(key))
			{
				Console.WriteLine("contains {0}", key);
			}
		}
	/*	{
			Dictionary<string, int> dic=new Dictionary<string, int>();
			dic.Add("zero", 0);
			dic.Add("one", 1);
			dic.Add("two", 2);

			Debug.Assert(dic.Count==3)

			// The Add method throws an exception if the new key is  
			// already in the dictionary. 
			try
			{
				dic.Add("zero", 0);
			}
			catch (ArgumentException)
			{
			}

			dic["zero"] = 0;
			// The indexer throws an exception if the requested key is 
			// not in the dictionary. 
			try
			{
				dic["N/A"]=1;
			}
			catch (KeyNotFoundException)
			{
			}

			// When a program often has to try keys that turn out not to 
			// be in the dictionary, TryGetValue can be a more efficient  
			// way to retrieve values. 
			int n;
			dic.TryGetValue("N/A", out n);

			// ContainsKey can be used to test keys before inserting  
			// them. 
			dic.ContainsKey("one");

			foreach(KeyValuePair<string, int> e in dic)
			{
				string k=e.Key;
				int v=e.Value;
			}

			// To get the values alone, use the Values property.
			Dictionary<string, int>.ValueCollection values = dic.Values;
			Dictionary<string, int>.KeyCollection keys = dic.Keys;

		        dic.Remove("two");
		}
//		{
//			Dictionary<string, int>[] dic = new Dictionary<string, int>[]
//			{
//				new Dictionary<string, int>(),
//				    new Dictionary<string, int>()
//			};
//		}
		{	
			Dictionary<string, int> dic=new Dictionary<string, int>();
			dic.Add("zero", 0);
			dic.Add("one", 1);
			dic.Add("two", 2);

//			Random rand = new Random();
//			int n=dic.ElementAt(rand.Next(0, dic.Count)).Value;
//			Console.WriteLine("{0}", n);

			foreach (object value in RandomValues(dic).Take(10))
			{
				Console.WriteLine(value);
			}

			dic.Clear();
		}*/
		
	}
}
