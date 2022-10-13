#ifndef TOGGLE_LIGHT_EVENT_H
#define TOGGLE_LIGHT_EVENT_H
//---------------------------------------------------------
#include <boost/statechart/event.hpp>
//---------------------------------------------------------
//struct toggle_light_event;
//---------------------------------------------------------
struct toggle_light_event:
	boost::statechart::event<toggle_light_event> 
{
};
//---------------------------------------------------------
#endif
