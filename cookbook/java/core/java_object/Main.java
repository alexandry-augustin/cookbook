class Base_00
{
	public int n=0;
}
class Base_01
{
}
class Base_02 extends Base_00
{
}
public class Main
{
	public static void main(String[] args)
	{
		{
			//http://docs.oracle.com/javase/6/docs/api/java/lang/Object.html
			Object o=new Object();
		//	Object b=new Base_00();
		//	o=b.clone();
		}
		{
			Object[] a={ new Base_00(), new Base_01(), new Base_02() };
		}
	}
}
