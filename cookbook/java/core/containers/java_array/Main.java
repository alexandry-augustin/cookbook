import java.util.Arrays;
//---------------------------------------------------------
// arrays can't be resized
// array extends Object 
// array implements the interfaces Cloneable and java.io.Serializable
// int[] a    <==>   int a[]
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
			int a[]={ 0, 1, 2, 3 };
			assert(a.length==4);
			for(int i=0; i<a.length; ++i)
				assert(a[i]==i);
		}
		{
			int a[]=new int[5];
			for(int i=0; i<a.length; ++i)
				a[i]=i;
			for(int i=0; i<a.length; ++i)
				assert(a[i]==i);
		}
		{
			int a[]=new int[5];
			try
			{
				System.out.println(a[10]);
			}
			catch(ArrayIndexOutOfBoundsException e)
			{
			}
		}
		{
			int a[]=new int[2];

			//"[I": run-time type signature for the class object "array with component type int"
			System.out.println(a.toString());

			System.out.println(a.getClass());
			System.out.println(a.getClass().getSuperclass());
		}
		{
			//public static void arraycopy(Object src, int src_pos, Object dest, int dest_pos, int n)
			//src_pos: starting position in the source array
			//dest_pos: starting position in the destination array
			//in: number of elements to copy

			int a_00[]={ 0, 1, 2, 3, 4, 5 };
			int a_01[]=new int[a_00.length];

			//copy a_00 in a_01
			assert(Arrays.toString(a_01).equals("[0, 0, 0, 0, 0, 0]"));
			System.arraycopy(a_00, 0, a_01, 0, a_00.length);
			assert(Arrays.toString(a_01).equals("[0, 1, 2, 3, 4, 5]"));
		}
		{
			int a_00[]={ 0, 1, 2, 3, 4, 5 };
			int a_01[]=new int[4];

			assert(Arrays.toString(a_01).equals("[0, 0, 0, 0]"));
			System.arraycopy(a_00, 2, a_01, 1, 3);
			assert(Arrays.toString(a_01).equals("[0, 2, 3, 4]"));
		}
		{
			//java.util.Arrays.copyOf(...)

			//Arrays.deepToString(a) for arrays within arrays
		}
	}
}
