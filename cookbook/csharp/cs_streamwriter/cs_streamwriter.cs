using System;

public class StreamWriter_
{
	static public void Main()
	{
		{
			System.IO.StreamWriter file = new System.IO.StreamWriter("out");
			file.WriteLine("a\nb\nc");
			file.Close();

			//append
			System.IO.StreamWriter file1 = new System.IO.StreamWriter("out", true);
			file1.WriteLine("0\n1\n2");
			file1.Close();
		}
		{
			//using (StreamWriter writer = new StreamWriter ("out"))
			//{
			//	writer.WriteLine ("na");
			//}
		}
		{
			System.IO.StreamWriter file = new System.IO.StreamWriter(Console.OpenStandardOutput());
			file.WriteLine("a\nb\nc");
			file.Close();
		}
	}
}
