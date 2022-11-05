// Strings

if(require.main === module)
{
	var s1 = "abc";
    var s2=new String("123");

	console.log(s1.length);
	console.log(s1.substring(1,3));

	var msg = [s1, s2].join(", ");
	console.log(msg);

	console.log(s1+' '+s2);
}
