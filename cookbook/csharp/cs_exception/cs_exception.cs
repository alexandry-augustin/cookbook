using System;

public class Exception_
{
	static public void Main()
	{
		{
			System.Exception o=null;
			try
			{
				throw o;
				//throw new System.InvalidOperationException("Logfile cannot be read-only");
			}
			catch(System.Exception e)
			{
			}
		}
		{
			throw new ArgumentException("error");
		}
		{
			try
			{
				return array[index];
			}
			catch (System.IndexOutOfRangeException ex)
			{
				System.ArgumentException argEx = new System.ArgumentException("Index is out of range", "index", ex);
				throw argEx;
			}
		}
	}
}
