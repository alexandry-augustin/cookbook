if(require.main === module)
{
    {
        let pattern = new RegExp("^.*\\.js$");
        // or
        // let pattern = /^.*\.js$/; // literal value

        let match = pattern.test("filename.js");
        console.assert(match);
    }
    {
        let idx = "01234.js".search(/\.js/);
        console.assert(idx == 5);
    }
    {
        const str = 'hello123!@#';

        const res = str.replace(/[^a-z]+/, ''); // remove not matching
        console.assert(res === 'hello');
    }
}
