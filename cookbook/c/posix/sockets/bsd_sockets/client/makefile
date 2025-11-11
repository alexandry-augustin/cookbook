PROGRAM		= bsd_socket_client
DEST		= bin/
SOURCES		= $(shell find src/ -type f -name '*.c')
OBJECTS		= $(SOURCES:%.c=%.o)
HEADERS		= $(shell find include/ -type f -name '*.h')
FLAGS		+= -g
FLAGS		+= -Iinclude/
LIBS_FLAGS	+= -ldl

$(PROGRAM): $(SOURCES)
	$(CC) $(FLAGS) $^ $(LIBS_FLAGS) -o $(DEST)$(PROGRAM)
run:
	./$(DEST)$(PROGRAM)
clean: 
	$(RM) $(DEST)$(PROGRAM)
	$(RM) $(OBJECTS)
