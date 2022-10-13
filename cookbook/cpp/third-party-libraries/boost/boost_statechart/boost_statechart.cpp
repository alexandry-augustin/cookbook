#include <iostream>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>

struct base_simple_state;
// Boost.Statechart makes heavy use of the curiously recurring
// template pattern. The deriving class must always be passed as
// the first parameter to all base class templates.

//when initiated, base_state_machine will be in base_simple_state state
struct base_state_machine:
	boost::statechart::state_machine<base_state_machine, base_simple_state> 
{
};

// For each state we need to define which state machine it
// belongs to and where it is located in the statechart. Both is
// specified with Context argument that is passed to
// simple_state<>. For a flat state machine as we have it here,
// the context is always the state machine. Consequently,
// base_state_machine must be passed as the second template parameter to
// base_simple_state's base (the Context parameter is explained in more
// detail in the next example).
struct base_simple_state:
	boost::statechart::simple_state<base_simple_state, base_state_machine> //base_simple_state belongs to base_state_machine
{
	// Whenever the state machine enters a state, it creates an
	// object of the corresponding state class. The object is then
	// kept alive as long as the machine remains in the state.
	// Finally, the object is destroyed when the state machine
	// exits the state. Therefore, a state entry action can be
	// defined by adding a constructor and a state exit action can
	// be defined by adding a destructor.
	base_simple_state() { std::cout << "Hello World!\n"; } // entry
	~base_simple_state() { std::cout << "Bye Bye World!\n"; } // exit
};

int main()
{
	{
		base_state_machine state_machine;// machine not yet running
		state_machine.initiate();//triggers the construction of the initial state base_simple_state

		// When we leave main(), state_machine is destructed what leads to
		// the destruction of all currently active states.
	}
	{
	}
	return 0;
}
