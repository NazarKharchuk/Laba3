#pragma once
#include <iostream>

class queue{
private:
	int* our_queue;	//Dynamic array for queue implementation
	int copasity;	//Queue capacity
	int start;		//The first element of the queue
	int end;		//The last element of the queue
	int num_elements;	//Number of elements
public:
	queue();		//Constructor
	~queue();		//Destructor

	void enqueue(int);		//Add an item to the queue
	void dequeue();			//Delete an item from the queue
	int first_element();	//Get the first item
	int last_element();		//Get the last item
};

