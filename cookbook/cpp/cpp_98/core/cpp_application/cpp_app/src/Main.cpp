#include <iostream>
#include "Application.h"
#include "Main.h"

Main::Main()
{
    std::cout<<"[Main::Main]"<<std::endl;
}

Main::~Main()
{
    std::cout<<"[Main::~Main]"<<std::endl;
}

int Main::main(int argc, char* argv[])
{
    std::cout<<"[Main::main]"<<std::endl;
    
    return 0;
}

BASE_APP_MAIN(Main)
