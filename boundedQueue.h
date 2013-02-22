#ifndef BOUNDEDQUEUE_H
#define BOUNDEDQUEUE_H

/*
Note: If you wanted to make this queue thread-safe, you would (for example) 
need to implement an atomic test_and_set function and a clear function, to 
manipulate some guard variable and make all public functions accessing the queue 
(in this case, enqueue and dequeue) atomic.  Not having access to a thread 
library here,  I have not made these member functions atomic.  My apologies :( .
 */
class BoundedQueue{
		int *theQueue;
		int start, end;
		unsigned int size;
		bool full, empty;
	public:
		BoundedQueue(unsigned int length);	//Constructor - sets queue size to length.
		BoundedQueue();			    //Default constructor - sets queue size to 3.
		~BoundedQueue();
		void enqueue(int value);	//Enqueues "value". If full, throws an instance of QueueIsFull
		int dequeue();				//Dequeues a value. If empty, throws an instance of QueueIsEmpty
};

//Exception classes
class QueueIsFull{};

class QueueIsEmpty{};

#endif