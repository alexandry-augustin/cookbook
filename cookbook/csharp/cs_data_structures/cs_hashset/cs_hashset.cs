//https://blog.udemy.com/c-sharp-hashset/
//---------------------------------------------------------
using System;
using System.Linq;
using System.Collections.Generic;
//---------------------------------------------------------
public class HashSet_
{
	static public void Main()
	{
		{
			HashSet<string> countries = new HashSet<string> { "JAPAN", "USA", "AUSTRALIA", "CANADA", "CHINA", "RUSSIA", "FRANCE" };
			countries.Add("ITALY");
			countries.Add("MEXICO");
			countries.Add("ITALY");
			Console.WriteLine(countries.Contains("AUSTRALIA"));
			Console.WriteLine(countries.Contains("ENGLAND"));
			foreach (string c in countries)
			{
				Console.WriteLine(c);
			}
		}
	}
}
