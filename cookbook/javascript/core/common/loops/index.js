//https://stackoverflow.com/questions/7480020/for-in-loop-with-string-array-outputs-indices

if(require.main === module)
{
    for(let i = 0; i < 3; i++)
    {
        text = "The number is " + i;
        console.log(text);
    }

    const numbers = [45, 4, 9, 16, 25];
    let txt = "";
    for(let x in numbers)
    {
      txt += numbers[x];
    }

    const person = {fname:"John", lname:"Doe", age:25};
    let text = "";
    for(let x in person)
    {
      text += person[x];
    }

    var words = ['word1', 'word2', 'word3'];
    words.forEach(function(value, index, array)
    {
        // here value is the array element being iterated
    });

    var words = ['word1', 'word2', 'word3'];
    for(const w of words)
    {
        console.log(w);
    }
}
