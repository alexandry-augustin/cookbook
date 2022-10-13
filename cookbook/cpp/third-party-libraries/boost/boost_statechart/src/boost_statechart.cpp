#include <iostream>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/thread.hpp>
//---------------------------------------------------------
//  --------------------------------
// |         base_state_00          |
// |--------------------------------|
// |           O                    |
// |           |                    |<----
// |           v                    |     | 
// |  ----------------------------  |     |
// | |        base_state_01       | |-----
// | |----------------------------| |
// |  ----------------------------  |
// |                |   ^           |
// |  base_event_00 |   |           |<-----O
// |                V   |           |
// |  ----------------------------  |
// | |         base_state_02      | |
// | |----------------------------| |
// |  ----------------------------  |
// |                                |
//  --------------------------------
//---------------------------------------------------------
struct base_state_00; //root state
struct base_state_01;
struct base_state_02;
//---------------------------------------------------------
struct base_event_00:
	boost::statechart::event<base_event_00>
{
	base_event_00()	{ std::cout<<"*"<<str()<<"*"<<std::endl; }
	std::string str() const { return "[event_00]"; }
};
//---------------------------------------------------------
struct base_state_machine: 
	boost::statechart::state_machine<base_state_machine, base_state_00>
{
	//data common to all states
};
//---------------------------------------------------------
struct base_state_00: 
	boost::statechart::simple_state<base_state_00, base_state_machine, base_state_01>
{
	typedef boost::statechart::transition<base_event_00, base_state_01> reactions;

	base_state_00() { std::cout<<"=>"<<str()<<std::endl; }
	~base_state_00() { std::cout<<"<="<<str()<<std::endl; }
	std::string str() const { return "[state_00]"; }
};
//---------------------------------------------------------
typedef
	typename boost::statechart::state_machine<base_state_machine, base_state_00>::state_iterator
	base_state_machine_it;
//---------------------------------------------------------
struct base_state_01: 
	boost::statechart::simple_state<base_state_01, base_state_00>
{
/*	typedef boost::mpl::list<
//		boost::statechart::custom_reaction<base_event_00>,
		boost::statechart::transition<base_state_00, base_state_00>
			> reactions;*/
	typedef boost::statechart::transition<base_event_00, base_state_02> reactions;

	base_state_01() { std::cout<<"=>"<<str()<<std::endl; }
	~base_state_01() { std::cout<<"<="<<str()<<std::endl; }
	std::string str() const { return "[state_01]"; }
};
//---------------------------------------------------------
struct base_state_02: 
	boost::statechart::simple_state<base_state_02, base_state_00>
{
	typedef boost::statechart::transition<base_event_00, base_state_01> reactions;

	base_state_02() { std::cout<<"=>"<<str()<<std::endl; }
	~base_state_02() { std::cout<<"<="<<str()<<std::endl; }
	std::string str() const { return "[state_02]"; }
};
//---------------------------------------------------------
int main()
{
	{
		base_state_machine b;
		b.initiate();
		char key;
		while(true)
		{
			std::cin>>key;
			switch(key)
			{
			case 'e':
				b.process_event(base_event_00());
				break;
			case 'q':
				break;
			default:
				std::cerr<<"unknown command"<<std::endl;
			}

			if(key=='q') break;
		}
	}
	{
	/*	base_state_machine b;
		b.initiate();
		//std::cout<<b.state_cast<const base_state_00&>().str()<<std::endl;
		for(base_state_machine_it it=b.state_begin(); it!=b.state_end(); ++it)
			std::cout<<typeid(*it).name()<<std::endl;
		boost::this_thread::sleep(boost::posix_time::seconds(2));
		b.process_event(base_event_00());*/
	}
	return 0;
}
