class MyItem {

    final int id;
    
    // MyItem({ 
    //     required this.id
    // });
    MyItem(this.id);

    String get name => "Item$id";
}

void main() {

    {
        int a=5;
        assert(a==5);
    }
    {
        dynamic n = 'five';
        n = 5;
        assert(n == 5);
    }
    {
        final l = List<MyItem>.generate(10, (id) => MyItem(id));
        l.removeWhere((item) => item.id == 1); // remove item
        MyItem findItem(int id) => l.firstWhere((item) => item.id == id);
        assert(findItem(2).name=='Item2');
        assert(findItem(4).name=='Item4');
        assert(findItem(6).name=='Item6');
    }

}