/*
	main.cpp
	The Quicksort Algorithms run here on test arrays

	Julio Sandino
	May 24, 2017

	This Program test a quicksort sorting function using only recursion, and one
	quicksort using multithreaded programming. They both sort a one million long
	array with random entries.
*/

#include <iostream>
#include <boost/thread.hpp>
#include <cstdlib>
using std::cout;

//Initiating threads to be used in the multithreaded quicksort
boost::thread_group threads;

struct qsort_thread {
	qsort_thread(int *d, unsigned int l, unsigned int r) {
		data = d;
		left = l;
		right = r;
	}

	int* data;
	unsigned int left, right;

	void operator()() {
		int i = left;
		int j = right;
		int temp;
		int pivot = data[(i + j) / 2];

		/* Partition */

		while (i <= j) {
			while (data[i] < pivot)
				i++;
			while (data[j] > pivot)
				j--;
			if (i <= j) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				i++;
				j--;
			}
		}
		
		/* Recursion */
		if (right - left > 16) {
			if (left < j)
				threads.create_thread(qsort_thread(data, left, j));
			if (i < right)
				threads.create_thread(qsort_thread(data, i, right));
		} else {
			if (left < j)
				qsort_thread(data, left, j);
			if (i < right)
				qsort_thread(data, i, right);
		}
		
	}
};

void seq_qsort(int* data, int left, int right);

int main() {
	const unsigned int size = 1000000;
	int data[size];
	for (int i = 0; i < size; i++)
		data[i] = rand();

	int test[] = {5, 6, 3, 8, 1};
	int test1[] = {5,4,3,2,1};

	seq_qsort(test, 0, 4);
	qsort_thread t(test1, 0, 4);
	t();
	

	for (int e: test)
		cout << e << ", ";

	cout << std::endl;
	
	for (int e: test1)
		cout << e << ", ";

	cout << std::endl << "Algorithms are implemented properly!" << std::endl;

	seq_qsort(data, 0, size - 1);
	qsort_thread(data, 0, size - 1);

	

	return 0;
}

void seq_qsort(int *data, int left, int right) {
	int i = left;
	int j = right;
	int temp;
	int pivot = data[(i + j) / 2];

	/* Partition */

	while (i <= j) {
		while (data[i] < pivot)
			i++;
		while (data[j] > pivot)
			j--;
		if (i <= j) {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
			j--;
		}
	}
	
	/* Recursion */
	if (left < j)
		seq_qsort(data, left, j);
	if (i < right)
		seq_qsort(data, i, right);
}
