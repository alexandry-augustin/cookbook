import java.util.ArrayList;
import java.util.Iterator;
import java.util.ListIterator;
import java.lang.Integer;
//---------------------------------------------------------
// class ArrayList extends AbstractList implements List { }
// dynamic arrays that can grow as needed
//---------------------------------------------------------
class base
{
	private int _n;
	public base(int n) { _n=n; }
	public int get() { return _n; }
	public void set(int n) { _n=n; }
}
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		{
			ArrayList<Integer> v=new ArrayList<Integer>();
			for(int i=0; i<10; ++i)
				v.add(new Integer(i));
			assert(v.size()==10);
			//----------------------------------------
			for(int i=0; i<v.size(); ++i)
				assert(v.get(i)==i);
		}
		{
			ArrayList<Integer> v=new ArrayList<Integer>(10);
			//System.out.println(v.size());
			//assert(v.size()==10);
			//v={ 0, 1, 2, 3 };
		}
	}
}
