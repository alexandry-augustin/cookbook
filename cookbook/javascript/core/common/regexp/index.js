if(require.main === module)
{
    let pattern = new RegExp("^.*\\.js$");
    // or
    // let pattern = /^.*\.js$/; // literal value

    let match = pattern.test("filename.js");
    console.log(match);

    let idx = "01234.js".search(/\.js/);
    console.log(idx);
}
