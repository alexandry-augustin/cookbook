//http://www.technical-recipes.com/2011/priority-queues-and-min-priority-queues-in-c/
//http://support.microsoft.com/kb/837697
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <vector>
#include <stdlib.h>
#include <cassert>

class base
{
public:
	int m_n;
private:
	std::vector<int>	m_priority;	//multi-level priorities
public:
	base(int n=0):
		m_n(n),
		m_priority(2, 0)
	{
	}
	//by default, std::priority_queue will maintain sort order if the priority is different
	//but if priority is same it will position elements randomly
	//the below code maintains the order of entries if the priorities are the same based on priotiy02
	
	int getPriority(int index) const
	{
		assert(index>=0);
		assert(index<m_priority.size());
		
		return m_priority[index];
	}
	
	void setPriority(int index, int priority)
	{
		assert(index>=0);
		assert(index<m_priority.size());
		
		m_priority[index]=priority;
	}
	bool operator<(const base& b) const
	{
		return true;//m_priority<b.m_priority;
//		if(lhs.getPriority(0)!=rhs.getPriority(0))
//			return lhs.getPriority(0)<rhs.getPriority(0);
//		else
//			return lhs.getPriority(1)>rhs.getPriority(1);
	}
	bool operator>(const base& b) const
	{
		return true;//m_priority>b.m_priority;
	}
	std::string str() const
	{
		std::stringstream ss;
		ss<<"[n:"<<m_n<<"] ";
		int i=0;
		for(std::vector<int>::const_iterator it=m_priority.begin(); it!=m_priority.end(); ++it)
			ss<<"[priority_"<<i++<<":"<<*it<<"] ";
		
		return ss.str();
	}
};

struct base_comp
{
	bool operator()(const base& lhs, const base& rhs) const
	{
		if(lhs.getPriority(0)!=rhs.getPriority(0))
			return lhs.getPriority(0)<rhs.getPriority(0);
		else
			return lhs.getPriority(1)>rhs.getPriority(1);
	}
};

class base_comp_ptr
{
public:
	bool operator()(const base* lhs, const base* rhs) const
	{
		if(lhs->getPriority(0)!=rhs->getPriority(0))
			return lhs->getPriority(0)<rhs->getPriority(0);
		else
			return lhs->getPriority(1)>rhs->getPriority(1);
	}
};

int main()
{
	//default:
	//	max priority queue
	//	std::vector<T>
	//the underlying container must be accessible through random access iterators and it must support:
	//	front()
	//	push_back()
	//	pop_back()
	
	{
		std::priority_queue<int> pq;
		pq.push(3);
		pq.push(5);
		pq.push(1);
		pq.push(8);
		
		while(!pq.empty())
		{
			std::cout<<pq.top()<<std::endl;
			pq.pop();
		}
	}
	{
		//std::priority_queue<base, std::vector<base>, base_comp> q;
		//std::priority_queue<base, std::vector<base>, std::greater<base> > q;
		//std::priority_queue<base, std::vector<base> > q;
		std::priority_queue<base> q;
		for(int i=0; i<10; ++i)
		{
			base b(rand()%10);
			b.setPriority(0, i);
			q.push(b);
		}	
		
		while(!q.empty())
		{
//			std::cout<<q.top().str()<<std::endl;
			q.pop();
		}
	}
	{
		std::priority_queue<base*, std::vector<base*>, base_comp_ptr> p;
		for(int i=0; i<10; ++i)
		{
			base* b=new base(i);
			{
				//b->setPriority(0, 0); //unordered
			}
			{
				//b->setPriority(0, 10-i); //ordered
			}
			{
				b->setPriority(0, 0);
				b->setPriority(1, 10-i); //ordered
			}
			p.push(b);
		}

		while(!p.empty())
		{
			std::cout<<p.top()->str()<<std::endl;
			delete p.top();
			p.pop();
		}
	}
	
	return 0;
}
