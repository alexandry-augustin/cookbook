import java.io.File;
import java.io.FilenameFilter;
import java.util.Arrays;
import java.util.regex.Pattern;
//---------------------------------------------------------
class RegexFilter implements FilenameFilter
{
	private Pattern pattern;
	public RegexFilter(String regex)
	{
		pattern=Pattern.compile(regex);
	}
	@Override
	public boolean accept(File dir, String name)
	{
		return pattern.matcher(name).matches();
	}
}
//---------------------------------------------------------
public class Main
{
	public static void main(String args[])
	{
		{
			//ls .
			File path=new File(".");
			String list[];
			list=path.list();
			try
			{
				list=path.list(new RegexFilter(".*.java"));
			}
			catch(Exception e)
			{
				System.err.println(e);
				System.exit(1);
			}
			Arrays.sort(list, String.CASE_INSENSITIVE_ORDER);
			for(String item: list)
				System.out.println(item);
		}
	}
}
