#include "queue.h"

void queue::enqueue(int item) {	//Add an item to the queue
	end++;
	our_queue[end] = item;
	num_elements++;
};

void queue::dequeue() {		//Delete an item from the queue
	start++;
	num_elements--;
}

int queue::first_element() {	//Get the first item
	int first = our_queue[start];
	return first;
}
int queue::last_element() {		//Get the last item
	int last = our_queue[end];
	return last;
}

