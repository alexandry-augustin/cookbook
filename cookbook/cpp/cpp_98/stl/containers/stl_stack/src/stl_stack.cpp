#include <stack>
#include <cassert>

int main()
{
	{
		std::stack<int> s;
		s.push(8);
		s.push(7);
		s.push(4);
		
		assert(s.top()==4);
		s.pop();
		assert(s.top()==7);
		s.pop();
		assert(s.top()==8);
		s.pop();
		assert(s.empty());
	
		//stack<int>::iterator i;
	}
	return 0;
}
