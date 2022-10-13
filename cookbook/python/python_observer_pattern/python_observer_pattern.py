class Subject:
    def __init__(self):
        self._observers=[]

    def attach(self, observer):
        if not observer in self._observers:
            self._observers.append(observer)

    def detach(self, observer):
        try:
            self._observers.remove(observer)
        except ValueError:
            pass

    def notify(self):
        for observer in self._observers:
                observer.update(self)

class Data(Subject):
    def __init__(self, name=''):
        Subject.__init__(self)
        self.name=name
        self.data=0

    def setData(self, data):
        self.data=data
        self.notify()

    def getData(self):
        return self.data

class HexView:
    def update(self, subject):
        print '[HexView::update] Subject %s has data 0x%x' % (subject.name, subject.getData())

class DecimalView:
    def update(self, subject):
        print '[DecimalView:update] Subject %s has data %d' % (subject.name, subject.getData())

if __name__=='__main__':
    data1=Data('Data 1')
    data2=Data('Data 2')
    view1=DecimalView()
    view2=HexView()
    data1.attach(view1)
    data1.attach(view2)
    data2.attach(view2)
    data2.attach(view1)

    data1.setData(10)
    data2.setData(15)
    data1.setData(3)
    data2.setData(5)
    data1.detach(view2)
    data2.detach(view2)
    data1.setData(10)
    data2.setData(15)

