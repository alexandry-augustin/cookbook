//disabled by default (they reduce performance)
//java -ea Main
//assert throws AssertionError but shouldn't be caught expicitly.
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args) 
	{
		{
			assert false;
			assert false : "false";
			assert 5==5;
			assert(5==5);
		}
	}
}
