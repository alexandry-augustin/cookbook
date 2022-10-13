#ifndef BUTTON_RELEASED_EVENT_H
#define BUTTON_RELEASED_EVENT_H
//---------------------------------------------------------
#include <iostream>
#include <boost/statechart/event.hpp>
//---------------------------------------------------------
struct button_released_event:
	boost::statechart::event<button_released_event>
{
	button_released_event()
	{
		std::cout<<"button [released]"<<std::endl;
	}
};
//---------------------------------------------------------
#endif
