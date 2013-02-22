#include <iostream>
#include "boundedQueue.h"
using namespace std;

int main(){
	BoundedQueue testQueue(4);
	cout<<"A 'full queue' error message should appear here:\n";
	try{
		testQueue.enqueue(7);							//Ensure all slots can be filled
		testQueue.enqueue(8);
		testQueue.enqueue(1);							
		testQueue.enqueue(0);
		testQueue.dequeue();
		testQueue.dequeue();
		testQueue.enqueue(1);							//Test wraparound
		testQueue.enqueue(5);
		testQueue.enqueue(9);
	}
	catch(QueueIsFull){									//Test that full queue exception is thrown
		cerr<<"Enqueue was called on a full queue,"
			<<" and an exception was thrown.  Good!\n";
	}
	cout<<"Queue values should be 1 - 0 - 1 - 5\n"
		<<"Queue values are ";
	for (int i = 0; i < 4; i++){						//Check queue values
		if (i == 3) cout<<testQueue.dequeue()<<endl;
		else cout<<testQueue.dequeue()<<" - ";
	}
	cout<<"An 'empty queue' error message should appear here:\n";
	try{
		testQueue.dequeue();
	}
	catch(QueueIsEmpty){								//Test that empty queue exception is thrown
		cerr<<"Dequeue was called on an empty queue,"
			<<" and an exception was thrown.  Good!\n";
	}
	return 0;
}
