#pragma once
#include <iostream>

using namespace std;

template <typename T>
class queue{
private:
	T* our_queue;	//Dynamic array for queue implementation
	int capasity;	//Queue capacity
	int start;		//The first element of the queue
	int end;		//The last element of the queue
	int num_elements;	//Number of elements
public:
	queue() {	//Constructor
		cout << "Queue capacity is: "; cin >> capasity;
		our_queue = new T[capasity];
		start = 0; end = -1; num_elements = 0;
	};		

	~queue() {	//Destructor
		delete[] our_queue;
	};		

	void enqueue(T);		//Add an item to the queue
	void dequeue();			//Delete an item from the queue
	T first_element();	//Get the first item
	T last_element();		//Get the last item
	bool is_empty();		//Checks if empty
	//void show();
};


template <typename T>
void queue<T>::enqueue(T item) {	//Add an item to the queue
	end++;
	our_queue[end] = item;

	for (int i = 1; i < end; ++i)
	{
		for (int k = 0; k < end - i; k++)
		{
			if (our_queue[k].d > our_queue[k + 1].d)
			{
				T temp = our_queue[k];
				our_queue[k] = our_queue[k + 1];
				our_queue[k + 1] = temp;
			}
		}
	}

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

/*template <typename T>
void queue<T>::show() {
	for (int i = start; i <= end; i++) {
		cout <<"("<< our_queue[i].i << " : " << our_queue[i].j << ")  " << our_queue[i].d;
	}
	cout << endl;
}*/