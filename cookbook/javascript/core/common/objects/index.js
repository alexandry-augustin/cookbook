function base_00()
{
	this.n=1;
	this.m=10;
}

if(require.main === module)
{
	var b_00=new base_00;

	console.log(b_00.n);
	console.log(b_00.m);
}
