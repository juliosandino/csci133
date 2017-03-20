#include <iostream>
#include <string>
#include <array>

int sum_evens(unsigned int n) {
	if (n == 1 || n == 0) // base case
		return 0;

	if (n % 2 == 0)
		return n + sum_evens (n - 2);
	else
		return n - 1 + sum_evens(n - 3);
}

int multiply(unsigned int a, unsigned int b) {
	if (b == 0)
		return 0;

	return a + multiply(a, b -1);
}

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

