INCLUDE_DIRS = -I. -I/home/ibutt/googletest-master/googletest/include
WARNINGS = -Wall -Werror
OBJECTS = buyorder.o buyorder.t.o
GTESTMAIN = /home/ibutt/googletest-master/googletest/make/gtest_main.a

buyorder : $(OBJECTS)
	g++ -o buyorder $(OBJECTS) $(GTESTMAIN) -lpthread
	
buyorder.o : buyorder.cpp buyorder.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c buyorder.cpp
	
buyorder.t.o : buyorder.t.cpp buyorder.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c buyorder.t.cpp
	
clean :
	rm $(OBJECTS) buyorder
