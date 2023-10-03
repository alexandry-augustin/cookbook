class MyItem {

    final int id;
    String get name => "Item$id";
    
    // MyItem({ 
    //     required this.id
    // });
    MyItem(this.id);
}

void main() {
    String s='test';
    assert(s=='test');

    int a=5;
    assert(a==5);

    List<int> l = [0, 1, 2];
    assert(l.length==3);
    assert(l[2]==2);

    final list = List<MyItem>.generate(10, (id) => MyItem(id));
    list.removeWhere((item) => item.id == 1); // remove item
    MyItem findItem(int id) => list.firstWhere((item) => item.id == id);
    assert(findItem(2).name=='Item2');
    assert(findItem(4).name=='Item4');
    assert(findItem(6).name=='Item6');

}