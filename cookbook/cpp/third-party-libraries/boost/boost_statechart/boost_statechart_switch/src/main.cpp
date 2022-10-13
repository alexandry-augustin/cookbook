#include "root_state.h"
#include "button_pressed_state.h"
#include "button_released_state.h"
#include "light_off_state.h"
#include "light_on_state.h"
//---------------------------------------------------------
int main()
{
	state_machine sm;
	sm.initiate();
	char key;
	while(true)
	{
		std::cin>>key;
		switch(key)
		{
		case 'p':
			sm.process_event(button_pressed_event());
			break;
		case 'r':
			sm.process_event(button_released_event());
			break;
		case 'q':
			break;
		default:
			std::cerr<<"unknown command"<<std::endl;
		}

		if(key=='q') break;
	}
	return 0;
}
