/*
Implement a MyQueue class which implements a queue using two stacks
*/

#include <iostream>
#include "headers/Queue.h"
#include "headers/MyQueue.h"

using namespace std;

int main(){

	// Reqular Queue
	Queue * q = new Queue;

	q->enqueue(1);
	q->enqueue(2);
	q->enqueue(3);
	q->enqueue(4);
	q->enqueue(5);

	cout << "Regular Queue:" << endl;
	cout << "==============" << endl;
	q->display();
	cout << endl;

	cout << "Dequeue: " << q->dequeue()->getData() << endl;
	cout << "Dequeue: " << q->dequeue()->getData() << endl;
	cout << "Dequeue: " << q->dequeue()->getData() << endl;
	cout << "Dequeue: " << q->dequeue()->getData() << endl;
	cout << "Dequeue: " << q->dequeue()->getData() << endl;
	cout << endl;

	// My Queue
	MyQueue * mq = new MyQueue;

	mq->enqueue(1);
	mq->enqueue(2);
	mq->enqueue(3);

	cout << mq->dequeue()->getData() << endl;
	cout << mq->dequeue()->getData() << endl;
	cout << mq->dequeue()->getData() << endl;
}