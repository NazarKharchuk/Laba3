#pragma once
#include <iostream>

using namespace std;

class queue{
private:
	int* our_queue;	//Dynamic array for queue implementation
	int capasity;	//Queue capacity
	int start;		//The first element of the queue
	int end;		//The last element of the queue
	int num_elements;	//Number of elements
public:
	queue() {	//Constructor
		cout << "Queue capacity is: "; cin >> capasity;
		our_queue = new int[capasity];
	};		

	~queue() {	//Destructor
		delete[] our_queue;
	};		

	void enqueue(int);		//Add an item to the queue
	void dequeue();			//Delete an item from the queue
	int first_element();	//Get the first item
	int last_element();		//Get the last item
};

