#include "boundedQueue.h"

///////////////////Constructors and destructors/////////////////////
BoundedQueue::BoundedQueue(unsigned int length){
	theQueue = new int[length];
	size = length;
	start = 0;
	end = 0;
	full = false;
	empty = true;
}

BoundedQueue::BoundedQueue(){
	theQueue = new int[3];
	size = 3;
	start = 0;
	end = 0;
	full = false;
	empty = true;
}

BoundedQueue::~BoundedQueue(){
	delete [] theQueue;
}

///////////////////Member Functions/////////////////////
void BoundedQueue::enqueue(int value){
	if (full){
		QueueIsFull queueIsFull;
		throw queueIsFull;
	}
	theQueue[end] = value;						//Place value at the back of the queue
	end = (end + 1)%size;						//Update the queue back index (end)
	empty = false;
	if (end == start){
		full = true;
	}
}

int BoundedQueue::dequeue(){
	if (empty){
		QueueIsEmpty queueIsEmpty;
		throw queueIsEmpty;
	}
	int value = theQueue[start];				//Grab the value at the front of the queue
	start = (start + 1)%size;					//Update the queue front index (start)
	full = false;
	if (start == end){
		empty = true;
	}
	return value;
}
