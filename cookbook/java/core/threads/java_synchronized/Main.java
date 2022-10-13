//http://www.javapractices.com/topic/TopicAction.do?Id=35

//an intrinsic lock is implied by each use of the synchronized keyword.
//In this case, the locking is performed by Java behind the scenes. (This is distinct from the programmer using or defining an explicit lock object themselves.)


//Each use of the synchronized keyword is associated with one of the two types of intrinsic lock:
//	an "instance lock", attached to a single object
//	a "static lock", attached to a class
//If a method is declared as synchronized, then it will acquire either the instance lock or the static lock when it is invoked, according to whether it is an instance method or a static method.
//The two types of lock have similar behaviour, but are completely independent of each other.


//acquiring the instance lock only blocks other threads from invoking a synchronized instance method; it does not block other threads from invoking an un-synchronized method, nor does it block them from invoking a static synchronized method.

//acquiring the static lock only blocks other threads from invoking a static synchronized method; it does not block other threads from invoking an un-synchronized method, nor does it block them from invoking a synchronized instance method.


//Outside of a method header, synchronized(this) acquires the instance lock.
//The static lock can be acquired outside of a method header in two ways:
//synchronized(Blah.class), using the class literal
//synchronized(this.getClass()), if an object is available




//http://stackoverflow.com/questions/10548066/multiple-object-locks-in-java
//Whether you use one or several locks by object depends on the coordination scheme you want to achieve, so it's entirely domain-specific. You must think through carefully which operations are and which aren't mutually exclusive and assign locks to them appropriately. There is no single best practice here. If you had more complex code where in at least one operation you needed to access both variables, that would tie them together and then you would need a single lock.


public class Main
{
	public static void main(String[] args)
	{
		{
			Base b=new Base();
		}
		{
			for(int i=0; i<10; ++i)
			{
				new Thread(new Runnable()
				{
					@Override
					public void run()
					{
						System.out.print(Base.get()+" ");
					}
				}).start();
			}
		}
	}
}
