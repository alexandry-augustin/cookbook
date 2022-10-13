#ifndef BUTTON_RELEASED_STATE_H
#define BUTTON_RELEASED_STATE_H
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
struct root_state;
struct button_pressed_state;
//---------------------------------------------------------
struct button_released_state:
	boost::statechart::simple_state<button_released_state,
		root_state::orthogonal<0> >
{
	typedef boost::statechart::transition<button_pressed_event,
		button_pressed_state> reactions;
};
//---------------------------------------------------------
#endif
