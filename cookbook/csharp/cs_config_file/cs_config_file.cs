using System;
using System.IO;
using System.Xml;
//using System.Linq;
//---------------------------------------------------------
public class Config_
{
	static public void Main()
	{
//		XElement booksFromFile = XElement.Load(@"books.xml");
//		Console.WriteLine(booksFromFile);
		XmlDocument doc = new XmlDocument ();
		doc.Load("config.xml"); 
		Console.WriteLine (doc.FirstChild.Name);
		//doc.ChildNodes[1].ChildNodes[0].ChildNodes[0].Attributes[0]
	}
}
