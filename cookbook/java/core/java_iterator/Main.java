import java.util.ArrayList;
import java.util.Iterator;
import java.util.ListIterator;
import java.lang.Integer;
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		ArrayList<Integer> v=new ArrayList<Integer>();
		for(int i=0; i<10; ++i)
			v.add(new Integer(i));
		//----------------------------------------
		Iterator<Integer> it=v.iterator();
		while(it.hasNext())
			System.out.print(it.next()+" ");
		System.out.print("\n");
		for(Iterator<Integer>it_=v.iterator(); it_.hasNext(); /*blank*/)
			System.out.print(it_.next()+" ");
		System.out.print("\n");

		//ListIterator<T> extends Iterator<T>
/*		ListIterator<Integer> list_it=v.listIterator();
		for()	
			System.out.println(it.next());*/
	}
}
