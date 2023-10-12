class MyItem {

    final int id;
    
    // MyItem({ 
    //     required this.id
    // });
    MyItem(this.id);
}

class MyWidget extends MyItem {

    MyWidget(int id): super(id)
    {

    }

}

void main() {
    {
        MyItem item = MyItem(5);
        assert(item.id == 5);
    }
    {
        MyWidget widget = MyWidget(9);
        assert(widget.id == 9);
    }
}