using System;
using System.IO;
//---------------------------------------------------------
public class File_
{
	static public void Main()
	{
		{
			string file = @"out";
			if(File.Exists(file))
			{
				File.Delete(file);
			}
			else
			{
			}
		}
		{
			StreamWriter file = new StreamWriter("filename");
			file.WriteLine("abc");
			file.Close();
		}
		{
			using (StreamWriter file = new StreamWriter("filename"))
			{
				file.WriteLine("");
			}
		}
	}
}
