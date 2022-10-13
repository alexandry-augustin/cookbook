using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Linq;

public class String
{
	static public void Main()
	{
		{
			Regex regex = new Regex("^abc.*");
			bool isMatch=regex.IsMatch("abc123");
			Console.WriteLine("{0}", isMatch);
		}
		{
			string pattern = @"^abc.*";
			Regex regex = new Regex(pattern);
			//Regex regex = new Regex(pattern, RegexOptions.IgnoreCase);
			MatchCollection matches = regex.Matches("abc123");
			if (matches.Count > 0)
			{
				foreach (Match match in matches)
					Console.WriteLine(match.Value);
			}
		}
		{
			Dictionary<string, int> dic=new Dictionary<string, int>();
			dic["abc"]=0;
			dic["bac"]=1;
			dic["bca"]=2;

			Regex regex = new Regex("^a.*");
			var dic1=dic.Where(i => regex.IsMatch(i.Key));

			foreach(KeyValuePair<string, int> e in dic1)
			{
				string k=e.Key;
				int v=e.Value;
				Console.WriteLine("{0}:{1}", k, v);
			}
		}
	}
}
