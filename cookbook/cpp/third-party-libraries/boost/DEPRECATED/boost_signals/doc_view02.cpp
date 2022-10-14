#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <functional>

#include <boost/signals.hpp>
#include <boost/bind.hpp>

struct IObserver;

struct IObservable
{
	virtual void registerObserver(IObserver& obs)=0;
	virtual void removeObserver(IObserver& obs)=0;
	virtual void notifyObservers()=0;
};

struct IObserver
{
	virtual void registerObservable(IObservable& obs)=0;
	virtual void removeObservable(IObservable& obs)=0;
	virtual void update(const IObservable& obs, std::string arg) const=0;
};

class Document: public IObservable
{
	std::string							m_text;
	boost::signal<void (const IObservable& o, std::string arg)>	m_signal;
	std::list<std::pair<IObserver*, boost::signals::connection> >	m_observers;												

public:
	//Document(const std::string& text=""): m_text(text) { }

	//IObservable
	void registerObserver(IObserver& observer)
	{	
		boost::signals::connection conn=
			m_signal.connect(boost::bind(&IObserver::update, &observer, _1, _2));
		m_observers.push_back(std::pair<IObserver*, boost::signals::connection>(&observer, conn));

	}
	void removeObserver(IObserver& observer)
	{ 
		std::list<std::pair<IObserver*, boost::signals::connection> >::iterator it;
		//it=std::find_if(m_observers.begin(), m_observers.end(), boost::bind(&Document::getObserver, _1)==observer))
		//it=std::find_if(m_observers.begin(), m_observers.end(), boost::bind(std::equal_to<IObserver>(), boost::bind(&T::value, _1), observer)		
		for(it=m_observers.begin(); it!=m_observers.end(); ++it)
			if(it->first==&observer)
				break;
		if(it!=m_observers.end())
			it->second.disconnect();
	}
	void notifyObservers() { m_signal(*this, m_text); }

	//Methods
	std::string get() const { return m_text; }
	void set(const std::string& text)
	{ 
		m_text=text; 

		std::cout<<"[Document] ["<<get()<<"]."<<std::endl;
		notifyObservers();
	}
};

class ViewOne: public IObserver
{
	//Document& m_document;

public:
		//ViewOne(Document& doc): m_document(doc) { m_document.registerObserver(*this); }
		//~ViewOne() { m_document.removeObserver(*this); }

		//IObserver
		//void registerObservable(IObservable& obs) {obs.registerObserver(*this); }
		//void removeObservable()	{ obs.removeObserver(*this); }
		void update(const IObservable& o, std::string arg) const
		{
			std::cout<<"[View1] ["<<arg<<"]."<<std::endl;
		}
};

class ViewTwo: public IObserver
{
	Document& m_document;

public:
	ViewTwo(Document& doc): m_document(doc)
	{
		m_document.registerObserver(*this);
	}
	~ViewTwo()
	{
		m_document.removeObserver(*this);
	}

	//IObserver
	void update(const IObservable& o, std::string arg) const
	{
		std::cout<<"[View2] ["<<arg<<"]."<<std::endl;
	}
};

int main(int argc, char* argv[])
{
	Document doc;
	ViewOne v1(doc);
	ViewTwo v2(doc);
	doc.set("Hello world!");

	return 0;
}