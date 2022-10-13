#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
//---------------------------------------------------------
#include <boost/statechart/state_machine.hpp>
//---------------------------------------------------------
class root_state;
//---------------------------------------------------------
struct state_machine:
	boost::statechart::state_machine<state_machine, root_state>
{
};
//---------------------------------------------------------
#endif
