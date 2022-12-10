#include <cassert>
#include <queue>

class base_00
{
	int _n;
public:
	base_00(int n=0): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

int main()
{
	{
		base_00* b=new base_00(19);
		std::queue<base_00*> q;
		
		q.push(b);
		assert(q.front()==b);
		q.pop();
		assert(b->get()==19);
		delete b;
		
		//rem: no .clear(). use
		//while(!q.empty()) pop();
		//or
		//q=std::queue<base_00*>();
		//or
		//std::queue<base_00*> empty; std::swap(q, empty);
	}
    {
        int a[]={0, 1, 2};
		std::queue<int> q;

        q.push(a[0]);
        q.push(a[1]);
        q.push(a[2]);

        assert(q.front()==0);
//        assert(q.back()==2);
        q.pop();
        assert(q.front()==1);
//        assert(q.back()==2);
        q.pop();
        assert(q.front()==2);
//        assert(q.back()==2);
        q.pop();
    }
	return 0;
}
