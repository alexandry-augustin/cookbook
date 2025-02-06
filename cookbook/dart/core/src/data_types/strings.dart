void main() {

    {
        String s='test';
        assert(s=='test');
    }
    {
        int n=5;
        String s="Item$n";
        assert(s=="Item5");
    }
    {
        String s1 = 'Single quotes work well for string literals.';
        String s2 = "Double quotes work just as well.";
        String s3 = 'It\'s easy to escape the string delimiter.';
        String s4 = "It's even easier to use the other delimiter.";
    }
    {
        String s = 'string interpolation';
        assert('Dart has $s, which is very handy.' == 'Dart has string interpolation, which is very handy.');
        assert('That deserves all caps. ${s.toUpperCase()} is very handy!' ==  'That deserves all caps. STRING INTERPOLATION is very handy!');
    }
    {
        String s = 'The + operator ' + 'works, as well.';
        assert(s == 'The + operator works, as well.');
    }
    {
        String s1 = '''
        You can create
        multi-line strings like this one.
        ''';

        String s2 = """This is also a
        multi-line string.""";
    }

}