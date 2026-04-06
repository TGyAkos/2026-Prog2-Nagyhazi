CCX = g++
CXXFLAGS = -Wall -Wdeprecated -pedantic -DMEMTRACE -g 

HEADERS := $(wildcard *.h) $(wildcard *.hpp)
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:%.cpp=%.o)

.PHONY: main
all: main

main: $(OBJECTS)
	$(CCX) -Wall -Werror -pedantic  $^ -g -o $@
	
%.o: %.c $(HEADERS)
	$(CCX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf $(OBJECTS) main
