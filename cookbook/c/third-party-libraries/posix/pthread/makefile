PROGRAM = bin/pthread
INCLUDEDIRS = -I/usr/include -Iinclude
LIBS += -lpthread
DEBUGFLAGS = -g -O0
CXXFLAGS = -DESRI_UNIX -Wall  $(INCLUDEDIRS) $(DEBUGFLAGS) 
CXX = g++
CXXSOURCES = $(wildcard src/*.c)
CXXOBJECTS = $(CXXSOURCES:.c=.o)
LDFLAGS = $(LIBDIRS) $(LIBS)

all: $(PROGRAM)

$(PROGRAM): $(CXXOBJECTS)
	$(CXX) -o $@ $(CXXOBJECTS) $(LDFLAGS)

run:
	./$(PROGRAM)

clean:
	$(RM) $(CXXOBJECTS)
	$(RM) $(PROGRAM)
