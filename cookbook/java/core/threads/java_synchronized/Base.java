import java.util.concurrent.atomic.AtomicInteger;

public class Base
{
	private static int _n=0;
	private AtomicInteger _atomic_n=new AtomicInteger(0);

	public static int get()
	{
		return _n++;
	}
	public static synchronized int get_sync()
	{
		return _n++;
	}
	public static int get_sync_stat()
	{
		//synchronized statement
		synchronized(Base.class)
		{
			++_n;
		}
		return _n;
	}
	public int get_atomic()
	{
		return _atomic_n.incrementAndGet();
	}
}
