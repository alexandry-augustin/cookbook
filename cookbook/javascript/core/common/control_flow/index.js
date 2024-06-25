if(require.main === module)
{
	{
		let condition = true;
		if(condition == true)
			console.assert(condition);
		else
			console.assert(!condition);

		if(!condition) {
			console.assert(!condition);
		}
	}
	{
		if(5 > 6) {

		}
		else {

		}
	}
}
