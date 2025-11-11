PROGRAM			= linux_nanosleep
DEST			= ./bin/
CXXSOURCES		= $(wildcard src/*.cpp)
CXXOBJECTS		= $(CXXSOURCES:%.cpp=%.o)
CXXHEADERS		= $(wildcard include/*.h)
CXXFLAGS		+= -g
CXXFLAGS		+= -Iinclude/
CXXFLAGS		+= -I/usr/local/include/
CXXFLAGS		+= -Wl,-rpath=/usr/local/lib/
CXXFLAGS		+= -L/usr/local/lib/
LIBS_FLAGS		+= -ldl
LIBS_FLAGS		+= -lpthread

$(PROGRAM): $(CXXOBJECTS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS_FLAGS) -o $(DEST)$(PROGRAM)
run:
	./$(DEST)$(PROGRAM)
clean: 
	$(RM) $(DEST)$(PROGRAM)
	$(RM) $(CXXOBJECTS)

