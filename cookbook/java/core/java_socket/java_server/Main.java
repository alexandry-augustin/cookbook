import java.net.*; //ServerSocket
import java.io.*;

class Acceptor implements Runnable
{
	public void run()
	{
		try
		{
			ServerSocket ss=new ServerSocket(4025);
			while(!Thread.interrupted())
				new Thread(new Session(ss.accept())).start();  //blocking
			// or, single-threaded, or a thread pool
		}
		catch(IOException ex)
		{
		}
	}
}
class Session implements Runnable
{
	final Socket _socket;

	Session(Socket socket)
	{
		_socket=socket;
	}
	public void run()
	{
		try
		{
			byte[] input=new byte[255];
			_socket.getInputStream().read(input);
			byte[] output=process(input);
			_socket.getOutputStream().write(output);
		}
		catch(IOException ex)
		{
		}
	}
	private byte[] process(byte[] cmd)
	{
		return new byte[255]; //TODO
	}
}
public class Main
{
	public static void main(String[] args) throws IOException
	{
		ServerSocket serverSocket=null;
		try
		{
			serverSocket=new ServerSocket(4444);
		}
		catch(IOException e)
		{
			System.err.println("Could not listen on port: 4444.");
			System.exit(1);
		}
		//-----------------------------------------
		Socket clientSocket=null;
		try
		{
			clientSocket=serverSocket.accept(); //blocking
		}
		catch(IOException e)
		{
			System.err.println("Accept failed.");
			System.exit(1);
		}
		System.out.println("connected");
		/*PrintWriter out=new PrintWriter(clientSocket.getOutputStream(), true);
		  BufferedReader in=new BufferedReader(
		  new InputStreamReader(
		  clientSocket.getInputStream()));
		  String inputLine, outputLine;
		  KnockKnockProtocol kkp=new KnockKnockProtocol();

		  outputLine=kkp.processInput(null);
		  out.println(outputLine);

		  while((inputLine=in.readLine()) != null)
		  {
		  outputLine=kkp.processInput(inputLine);
		  out.println(outputLine);
		  if(outputLine.equals("Bye."))
		  break;
		  }
		  out.close();
		  in.close();*/

		clientSocket.close();
		serverSocket.close();
	}
}
