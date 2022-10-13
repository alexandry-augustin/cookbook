//	Modifier    | Class | Package | Subclass | World
//	————————————+———————+—————————+——————————+———————
//	public      |  ✔    |    ✔    |    ✔     |   ✔
//	————————————+———————+—————————+——————————+———————
//	protected   |  ✔    |    ✔    |    ✔     |   ✘
//	————————————+———————+—————————+——————————+———————
//	no modifier |  ✔    |    ✔    |    ✘     |   ✘
//	————————————+———————+—————————+——————————+———————
//	private     |  ✔    |    ✘    |    ✘     |   ✘
//---------------------------------------------------------
//generic interface
interface IBase_00<T>
{
	public T get();
}
//---------------------------------------------------------
//generic class
class Base_00<T>
{
	private T _t;
	Base_00(T t) { _t=t; }
	public T get() { return _t; }
	public void set(T t) { _t=t; }
}
//---------------------------------------------------------
/*class Base_00<String>
{
	public T get()
	{
		return "changed";
	}
}*/
//---------------------------------------------------------
/*class Base_01<? extends Base_00>
{
}*/
//---------------------------------------------------------
class Base_02
{
	public static <T> T get_00(T t) //generic method
	{
		return t;
	}
	public static <T> Base<T> get_01(T t)
	{
		return new Base<T>(t);
	}
	/*public static <T extends Base_00<T>> T get_02(T t)
	{
		return t.get();
	}*/
}
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		{
			//Base_00<int> b; //nok for built-in types
		}
		{
			Base_00<Integer> b=new Base_00<Integer>(5);
			assert(b.get()==5);
		}
		{
			Base_02 b=new Base_02();

			assert(b.get_00(5)==5); //type argument inference
			//or
			assert(b.<Integer>get_00(5)==5); //type argument inference

			assert(b.get_01(5).get()==5);
			//assert(b.get_02(new Base_00(5))==5);
		}
	}
}
