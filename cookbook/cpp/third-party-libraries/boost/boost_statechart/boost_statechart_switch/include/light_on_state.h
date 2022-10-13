#ifndef LIGHT_ON_STATE_H
#define LIGHT_ON_STATE_H
//---------------------------------------------------------
#include <iostream>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include "button_pressed_event.h"
#include "button_released_event.h"
#include "toggle_light_event.h"
#include "state_machine.h"
//---------------------------------------------------------
class root_state;
//---------------------------------------------------------
struct light_on_state:
	boost::statechart::simple_state<light_on_state,
		root_state::orthogonal<1> >
{
	typedef boost::statechart::transition<toggle_light_event,
		light_off_state> reactions;

	light_on_state()
	{
		std::cout<<"light [on]"<<std::endl;
	}
};
//---------------------------------------------------------
#endif
