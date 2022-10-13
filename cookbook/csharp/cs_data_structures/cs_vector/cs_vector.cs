using System;

public class Vector
{
	static public void Main()
	{
		//Vector v=new Vector<int> {1, 2, 3};
		//Vector v=new Vector(3,0);
		Vector[] v = new Vector[3];

		foreach(var item in v)
			Console.WriteLine(item);
	}
}

