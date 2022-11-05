function choose(choices)
{
    var index = Math.floor(Math.random() * choices.length);
    return choices[index];
}

if(require.main === module)
{
	let notes = ["C", "D", "E", "F", "G", "A", "B"];
	let note = choose(notes);
	console.log(note)
}
