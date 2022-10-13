#ifndef ROOT_STATE_H
#define ROOT_STATE_H
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
struct button_released_state;
struct light_off_state;
//---------------------------------------------------------
struct root_state:
	boost::statechart::simple_state<root_state, state_machine,
		boost::mpl::list<button_released_state, light_off_state> >
{
};
//---------------------------------------------------------
#endif
