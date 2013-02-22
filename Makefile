all: staticTest dynamicTest

dynamicTest: dynamicTest.o boundedQueue.o
	g++ dynamicTest.o boundedQueue.o -o dynamicTest

dynamicTest.o: dynamicTest.cpp
	g++ -c dynamicTest.cpp

staticTest: staticTest.o boundedQueue.o
	g++ staticTest.o boundedQueue.o -o staticTest

staticTest.o: staticTest.cpp
	g++ -c staticTest.cpp

boundedQueue.o: boundedQueue.cpp
	g++ -c boundedQueue.cpp

clean:
	rm -rf *o staticTest dynamicTest