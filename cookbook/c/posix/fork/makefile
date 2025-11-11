PROGRAM			= fork
DEST			= bin/
CXXSOURCES		= $(shell find src/ -type f -name '*.c')
CXXOBJECTS		= $(CXXSOURCES:%.c=%.o)
CXXHEADERS		= $(shell find include/ -type f -name '*.h')
CXXFLAGS		+= -g
CXXFLAGS		+= -Iinclude/
LIBS_FLAGS		+= -ldl

$(PROGRAM): $(CXXOBJECTS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS_FLAGS) -o $(DEST)$(PROGRAM)
run:
	./$(DEST)$(PROGRAM)
clean: 
	$(RM) $(DEST)$(PROGRAM)
	$(RM) $(CXXOBJECTS)
