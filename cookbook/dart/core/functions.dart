void f_00() {
    print('test');
}

int f_01(n) {
    return n;
}

String f_02() => 'test';

void main() {
    {
        f_00();
    }
    {
        int n = f_01(5);
        assert(n==5);
    }
    {
        assert(f_02() == 'test');
    }
}