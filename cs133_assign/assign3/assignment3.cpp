#include <iostream> 
#include <string>
#include <array>

/*
--Inductive Proof sum_evens--

best case: n = 0 or n = 1
	it will return 0 because neither 0 or 1 are even

Inductive case:

	Hypothesis:
		sum_evens(n') = n' + (n' - 2) + (n' - 4) + ... + 2
		for all n' < n

		let n' = n - 2

	Prove sum_evens(n) =  n + (n - 2) + (n - 4) + (n - 6) + ... + (2)

	--when n is even--
	n + sum_evens(n - 2) - n = n + (n - 2) + (n - 4) + (n - 6) + ... + 2 - n
	sum_evens(n - 2) = (n - 2) + (n - 4) + (n - 6) + ... + 2
	sum_evens(n') = n' + (n' - 2) + (n' - 4) + ... + 2

	--when n is odd--
	n - 1 + sum_evens(n - 3) - (n - 1) = (n - 1) + (n - 3) + (n - 5) + ... + 2 - (n - 1)
	sum_evens(n - 3) = (n - 3) + (n - 5) + ... + 2
	sum_evens(n' - 1) = (n' - 1) + (n' - 3) + ... + 2

*/
int sum_evens(unsigned int n) {
	if (n == 1 || n == 0) // base case
		return 0;

	if (n % 2 == 0)
		return n + sum_evens (n - 2);
	else
		return n - 1 + sum_evens(n - 3);
}

/*
--Inductive Proof sum_evens--

best case: b = 0
	0 = 0

Inductive Case:

	Hypothesis:
		multiply(a, b') = a * b'
		for all b' < b

		let b' = b - 1
	
	Prove multiply(a, b) = a * b

	a + multiply(a, b - 1) - a	= a * b - a
	multiply(a, b - 1) = a * (b - 1)
	multiply(a, b') = a * b'

*/
int multiply(unsigned int a, unsigned int b) {
	if (b == 0)
		return 0;

	return a + multiply(a, b - 1);
}
/*
--Inductive Proof smallest--

This proof tests that the function recursively checks every object
in the array, assuming that the comparison is handled elsewhere.

best case: length = 1
	it will return the only number in the array

Inductive case:
	
	Hypothesis:
		when length = 1, the array will have been fully checked.
	
	Prove smallest(int* arr, length) checks every element in array

	every time the function gets called it recursively calls itself with
	length - 1, until length = 1.
	
 
 */
int smallest(int* arr, int length) {
	if (length == 1)
		return *arr;
	
	int current = *arr;
	int rest = smallest(arr+1, length-1);

	return current < rest ? current : rest;
}



bool is_palindrome(std::string s) {
	if (s.length() == 0)
		return true;

	if (s.at(0) == s.at(s.length() - 1))
		return is_palindrome(s.substr(1, s.length() - 2));
	else
		return false;
}

bool is_element_of(int i, int* array, int length) {
	if (length == 0)
		return false;
	
	if (i == *array)
		return true;
	else 
		return is_element_of(i, array + 1, length - 1);
}

bool is_subset(int* a, int length_a, int* b, int length_b) {
	if (length_a == 0)
		return true;
	if (length_b == 0)
		return false;

	if (*a == *b)
		return is_subset(a + 1, length_a - 1, b + 1, length_b - 1);
	else
		return is_subset(a, length_a, b + 1, length_b - 1);
}

void print_arr(int arr[], int length) {
	std::cout << "[";
	for (int i = 0; i < length - 1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[length - 1] << "]";
}

