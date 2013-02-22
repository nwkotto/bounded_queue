#include <iostream>
#include <string>
#include "boundedQueue.h"
using namespace std;

void printHelp();

unsigned int inputQueueSize();									//Get queue size from user

int main(){
	BoundedQueue *boundedQueue;									//Make the queue
	unsigned int queueSize = inputQueueSize();
	boundedQueue = new BoundedQueue(queueSize);
	printHelp();
	string input1, input2;
	int newVal;
	unsigned int occupancy = 0;
	try{
		while(1){
			cout<<"-_- % ";
			cin>>input1;										//Get parameter 1
			if (cin.good()) getline(cin, input2);				//Get parameter 2
			if (input1 == "enqueue" || input1 == "e"){			//enqueue
				if (!input2.empty()){
					if (input2 == "0") newVal = 0;
					else{
						newVal = atoi(input2.c_str());
						if (newVal == 0){
							cerr<<"Invalid value.  Try again\n";
							continue;
						}
					}
					occupancy++;
					boundedQueue->enqueue(newVal);
					cout<<"Enqueueing "<<newVal<<endl;
				}
				else{
					cerr<<"No value passed.  Try again.\n";
				}
			}
			else if (input1 == "dequeue" || input1 == "d"){		//dequeue
				occupancy--;
				newVal = boundedQueue->dequeue();
				cout<<"Dequeued value: "<<newVal<<endl;
			}
			else if (input1 == "occupancy" || input1 == "o"){	//occupancy
				cout<<occupancy<<"/"<<queueSize<<endl;
			}
			else if (input1 == "new" || input1 == "n"){			//new
				delete boundedQueue;
				queueSize = inputQueueSize();
				boundedQueue = new BoundedQueue(queueSize);
				occupancy = 0;
			}
			else if (input1 == "help" || input1 == "h"){		//help
				printHelp();
			}
			else if (input1 == "quit" || input1 == "q"){		//quit
				cout<<"Quitting.\n";
				delete boundedQueue;
				exit(0);
			}
			else{
				cerr<<"Command not recognized.  Try again.\n";
			}
		}
	}
	catch(QueueIsFull){									//Catches 'full queue' exceptions
		cerr<<"Enqueue was called on a full queue,"
			<<" and an exception was thrown.\n"
			<<"Quitting.\n";
		exit(1);
	}
	catch(QueueIsEmpty){								//Catches 'empty queue' exceptions
		cerr<<"Dequeue was called on an empty queue,"
			<<" and an exception was thrown.\n"
			<<"Quitting.\n";
		exit(1);
	}
	return 0;
}

void printHelp(){
	cout<<"Commands:\n"
		<<"\tEnqueue element: 'enqueue <value>' OR 'e <value>'\n"
		<<"\tDequeue element (cout value): 'dequeue' OR 'd'\n"
		<<"\tOccupancy (cout numValues/capacity): 'occupancy' OR 'o'\n"
		<<"\tNew Queue: 'new' OR 'n'\n"
		<<"\tHelp (see this screen again): 'help' OR 'h'\n"
		<<"\tQuit:'quit' OR 'q'\n"
		<<"\n\tNote: If you try to add to a full queue or remove from an empty queue, an exception\n"
		<<"\twill be thrown and the program will exit with code 1.\n";
}

unsigned int inputQueueSize(){
	cout<<"How big do you want your queue to be (type an unsigned int)? ";
	string queueString;
	cin>>queueString;
	unsigned int queueSize = atoi(queueString.c_str());
	while (queueSize == 0){
		cerr<<"Bad queue size.  Try again: ";
		cin>>queueString;
		queueSize = atoi(queueString.c_str());
	}
	return queueSize;
}
