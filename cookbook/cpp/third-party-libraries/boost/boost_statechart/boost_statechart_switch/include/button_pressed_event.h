#ifndef BUTTON_PRESSED_EVENT_H
#define BUTTON_PRESSED_EVENT_H
//---------------------------------------------------------
#include <iostream>
#include <boost/statechart/event.hpp>
//---------------------------------------------------------
struct button_pressed_event:
	boost::statechart::event<button_pressed_event>
{
	button_pressed_event()
	{
		std::cout<<"button [pressed]"<<std::endl;
	}
};
//---------------------------------------------------------
#endif
