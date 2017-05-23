#include <iostream>
#include <boost/thread.hpp>
using std::cout;

struct qsort_thread {
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
	if (left < j)
		new boost::thread {qsort_thread(data, left, j)};
	if (i < right)
		new boost::thread {qsort_thread(data, i, right)};
	
	}
}

void seq_qsort(int* data, int left, int right);
void par_qsort(int* data, int left, int size);

int main() {

	int test[] = {5, 4, 3, 2, 1};

	seq_qsort(test, 0, 5);

	for (int e: test)
		cout << e << ", ";

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


void par_qsort(int *data, int left, int right) {
}
