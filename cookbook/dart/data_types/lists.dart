void main() {
    {
        List l = [0, 'a', .5];
    }
    {
        List<int> l = [0, 1, 2];

        assert(l.length==3);
        assert(l[2]==2);
    }
    {
        List<int> l = [];
        l.add(3);

        assert(l[0]==3);
    }
    {
        List<String> l = ['0', '1', '2', '1'];
        l.remove('1'); // remove first instance only

        assert(l.length==3);
        assert(l[1]=='2');

        
    }
}