import java.util.Set;
//---------------------------------------------------------
class ImplementsRunnable implements Runnable
{
	private Thread	_thread;

	@Override
	public void run()
	{
		System.out.println("running");
	}
}
//---------------------------------------------------------
class ExtendsThread extends Thread
{
	@Override
	public void run()
	{
		System.out.println("running");
	}
}
//---------------------------------------------------------
public class Main
{
	public static void main(String[] args)
	{
		{
			Set<Thread> threadSet=Thread.getAllStackTraces().keySet();
			Thread[] threadArray=threadSet.toArray(new Thread[threadSet.size()]);

			int nb_threads=Thread.getAllStackTraces().keySet().size();
			System.out.println(nb_threads);
		}
		{
			long id=Thread.currentThread().getId();
			System.out.println(id);
		}
		{
			System.out.println("minimal priority: "+Thread.MIN_PRIORITY);
			System.out.println("maximal priority: "+Thread.MAX_PRIORITY);
			System.out.println("norm priority: "+Thread.NORM_PRIORITY);
		}
		{
			ExtendsThread ext=new ExtendsThread();
			ext.start();
			try
			{
				//sleep is a static method of Thread
				Thread.currentThread().sleep(1);
				//or
				Thread.sleep(1);
			}
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		{
			Runnable imp=new ImplementsRunnable();
			Thread thread=new Thread(imp);
			thread.setName("test");
			thread.setPriority(5); //high=>higher priority
			thread.start();
		}
		{
			Thread thread=new Thread(new Runnable()
			{
				@Override
				public void run()
				{
				}
			});
			thread.start();
		}
		{
			new Thread(new Runnable()
			{
				@Override
				public void run()
				{
				}
			}).start();
		}
		{
			Thread thread=new Thread()
			{
				@Override
				public void run()
				{
					try
					{
						//InterruptedException thrown if thread interrupted while sleeping (.interrupt())
						Thread.currentThread().sleep(1000); //ms
					}
					catch(InterruptedException e)
					{
						e.printStackTrace();
					}
				}
			};
			thread.start();
			try
			{
				thread.join();
			}
			catch(Exception e)
			{
				assert(false);
			}
		}
	}
}
