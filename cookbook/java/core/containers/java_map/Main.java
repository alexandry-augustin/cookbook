import java.util.Map;
import java.util.HashMap;

public class Main
{
	public static void main(String[] args)
	{
		{
			Integer n=new Integer(0);
			Map<Integer, String> m=new HashMap<Integer, String>();
			m.put(0, "zero");
			m.put(new Integer(5), "five");
			assert(m.get(0)=="zero");
		}
	}
}
