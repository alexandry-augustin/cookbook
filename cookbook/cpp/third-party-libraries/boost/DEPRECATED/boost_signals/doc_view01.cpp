//http://www.codeproject.com/script/Articles/ViewDownloads.aspx?aid=888

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <functional>

#include <boost/signals.hpp>
#include <boost/bind.hpp>

struct Observer;

struct Subject
{
	virtual void attach(Observer& obs)=0;
	virtual void detach(Observer& obs)=0;
	virtual void notify()=0;
};

struct Observer
{
	virtual void update(const Subject& subject) const=0;
};

class Document: public Subject
{
	std::string							m_text;
	boost::signal<void (const Subject& subject)>			m_signal;
	std::list<std::pair<Observer*, boost::signals::connection> >	m_observers;												

public:
	//Document(const std::string& text=""): m_text(text) { }
	~Document()
	{
		detachAll();
	}
	
	void attach(Observer& obs)
	{	
		boost::signals::connection conn=
			m_signal.connect(boost::bind(&Observer::update, &obs, _1));
		m_observers.push_back(std::pair<Observer*, boost::signals::connection>(&obs, conn));
	}
	void detach(Observer& obs)
	{ 
		//std::list<std::pair<Observer*, boost::signals::connection> >::iterator it;
		//it=std::find_if(m_observers.begin(), m_observers.end(), boost::bind(&Document::getObserver, _1)==observer))
		//it=std::find_if(m_observers.begin(), m_observers.end(), boost::bind(std::equal_to<IObserver>(), boost::bind(&T::value, _1), observer)		
		//v.erase( remove_if(v.begin(), v.end(), is_odd), v.end() );
		std::list<std::pair<Observer*, boost::signals::connection> >::iterator it=m_observers.begin();
		while(it!=m_observers.end())
			if(it->first==&obs)
			{
				it->second.disconnect();
				m_observers.erase(it++);
			}
			else
				++it;
	}
	void notify() { m_signal(*this); }
	
	void detachAll()
	{
		std::list<std::pair<Observer*, boost::signals::connection> >::iterator it;
		for(it=m_observers.begin(); it!=m_observers.end(); ++it)
			it->second.disconnect();
	}
	int nbOfObservers() const { return m_observers.size(); }
	std::string getState() const { return m_text; }
	void setState(const std::string& text)
	{ 
		m_text=text; 

		std::cout<<"[Document] ["<<m_text<<"]."<<std::endl;
		notify();
	}
};

class View: public Observer
{
	Document& m_document;

public:
	View(Document& doc): m_document(doc) { m_document.attach(*this); }
	~View() { m_document.detach(*this); }
	
	void update(const Subject& subject) const
	{
		if(&subject==&m_document)
		{
			std::cout<<"[View] ["<<m_document.getState()<<"]."<<std::endl;
		}
	}
};

class CompositeView: public Observer
{
	Document& m_document1;
	Document& m_document2;

public:
	CompositeView(Document& doc1, Document& doc2): m_document1(doc1), m_document2(doc2) 
	{
		m_document1.attach(*this); 
		m_document2.attach(*this); 
	}
	~CompositeView()
	{ 
		m_document1.detach(*this); 
		m_document2.detach(*this); 
	}
	
	void update(const Subject& subject) const
	{
		if(&subject==&m_document1)
		{
			std::cout<<"[CompositeView] [Document1] ["<<m_document1.getState()<<"]."<<std::endl;
		}
		if(&subject==&m_document2)
		{
			std::cout<<"[CompositeView] [Document2] ["<<m_document2.getState()<<"]."<<std::endl;
		}
	}
};

int main(int argc, char* argv[])
{
	Document* doc1=new Document();
	Document* doc2=new Document();
	View* v1=new View(*doc1);
	View* v2=new View(*doc2);
	CompositeView* cv1=new CompositeView(*doc1, *doc2);
	
	doc1->setState("Hello");
	std::cout<<"####################"<<std::endl;
	doc2->setState("World!");
	
	delete v1; delete v2; delete cv1;
	delete doc1; delete doc2;
	
	return 0;
}