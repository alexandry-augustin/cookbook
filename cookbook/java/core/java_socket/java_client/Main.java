import java.net.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		Socket socket=null;
//		PrintWriter out=null;
//		BufferedReader in=null;
		try
		{
			socket=new Socket("localhost", 4444);
//			out=new PrintWriter(socket.getOutputStream(), true);
//			in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
		}
		catch(UnknownHostException e)
		{
			System.err.println("Don't know about host: taranis.");
			System.exit(1);
		}
		catch(IOException e)
		{
			System.err.println("Couldn't get I/O for the connection to: taranis.");
			System.exit(1);
		}
/*		BufferedReader stdIn=new BufferedReader(new InputStreamReader(System.in));
		String fromServer;
		String fromUser;
		while((fromServer=in.readLine())!=null)
		{
			System.out.println("Server: "+fromServer);
			if(fromServer.equals("Bye."))
				break;
			fromUser=stdIn.readLine();
			if (fromUser != null)
			{
				System.out.println("Client: "+fromUser);
				out.println(fromUser);
			}
		}
		out.close();
		in.close();
		stdIn.close();*/
		socket.close();
	}
}
