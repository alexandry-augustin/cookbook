#ifndef BUTTON_PRESSED_STATE_H
#define BUTTON_PRESSED_STATE_H
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
struct button_released_state;
//---------------------------------------------------------
struct button_pressed_state:
	boost::statechart::state<button_pressed_state,
		root_state::orthogonal<0> >
{
	typedef boost::statechart::transition<button_released_event,
		button_released_state> reactions;

	button_pressed_state(my_context ctx):
		my_base(ctx)
	{
		post_event(toggle_light_event());
	}
};
//---------------------------------------------------------
#endif
