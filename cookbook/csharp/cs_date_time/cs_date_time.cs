using System;
using System.Globalization;
using System.Collections.Generic;

public class DateTime_
{
	static public void Main()
	{
		{
			Console.WriteLine(DateTime.Now.ToString(new CultureInfo("en-GB")));

			DateTime start = DateTime.Now;
			DateTime end = DateTime.Now;
			TimeSpan delta = end-start;

			Console.WriteLine(delta.TotalHours);
			Console.WriteLine(delta.TotalMilliseconds);
			
		}
	}
}
