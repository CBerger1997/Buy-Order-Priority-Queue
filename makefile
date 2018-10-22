INCLUDE_DIRS = -I. -I/home/ibutt/googletest-master/googletest/include
WARNINGS = -Wall -Werror
OBJECTS = buyorder.o buyorder.t.o sellorder.o sellorder.t.o priorityqueue.t.o
GTESTMAIN = /home/ibutt/googletest-master/googletest/make/gtest_main.a

priorityqueue : $(OBJECTS)
	g++ -o priorityqueue $(OBJECTS) $(GTESTMAIN) -lpthread
	
buyorder.o : buyorder.cpp buyorder.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c buyorder.cpp
	
buyorder.t.o : buyorder.t.cpp buyorder.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c buyorder.t.cpp
	
sellorder.o : sellorder.cpp sellorder.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c sellorder.cpp
	
sellorder.t.o : sellorder.t.cpp sellorder.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c sellorder.t.cpp
	
priorityqueue.t.o : priorityqueue.t.cpp priorityqueue.h
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c priorityqueue.t.cpp
	
clean :
	rm $(OBJECTS) priorityqueue