/*#include "queue.h"

template <typename T>
void queue<T>::enqueue(T item) {	//Add an item to the queue
	end++;
	our_queue[end] = item;
	num_elements++;
};

template <typename T>
void queue<T>::dequeue() {		//Delete an item from the queue
	start++;
	num_elements--;
}

template <typename T>
T queue<T>::first_element() {	//Get the first item
	T first = our_queue[start];
	return first;
}

template <typename T>
T queue<T>::last_element() {		//Get the last item
	T last = our_queue[end];
	return last;
}

template <typename T>
bool queue<T>::is_empty() {		//Checks if empty
	if (num_elements) return false;
	else return true;
}

template <typename T>
void queue<T>::show() {
  for (int i = start; i <= end; i++) {
	cout << our_queue[i]<< "  ";
  }
  cout << endl;
}*/