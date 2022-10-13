using System;

public class base_00
{
	public double n { get; set; } //Auto-Implemented Properties

	static public void Main ()
	{
		base_00 b=new base_00();
		Console.WriteLine(b.n);
		b.n=5;
		//Debug.Assert(b.n==5);

	}
}
