#include "assignment3.cpp"
using std::cout;

int main () {
	int sum = sum_evens(7);
	cout << "sum_evens(7): " << sum << std::endl;

	int mult = multiply(5, 4);
	cout << "multiply(5, 4): " << mult << std::endl;

	int arr[] = {6, 5, 1, 3, 4, 7};
	int min = smallest(arr, 6);
	cout << "smallest (expected 1): " << min << std::endl;
	
	std::string pal = "kayak";
	std::string not_pal = "aabbddaa";
	if (is_palindrome(pal) && !is_palindrome(not_pal))
		cout << pal << " is a palindrome!" << std::endl
			<< not_pal << " is not!" << std::endl;

	int val = 8;
	if (is_element_of(val, arr, 6)) {
		cout << val << " is an element of the array ";
		print_arr(arr, 6);
		cout << std::endl;
	}
	else {
		cout << val << " is not an element of the array ";
		print_arr(arr, 6);
		cout << std::endl;
	}
	
	int val1 = 1;

	if (is_element_of(val1, arr, 6)) {
		cout << val1 << " is an element of the array ";
		print_arr(arr, 6);
		cout << std::endl;
	}
	else {
		cout << val1 << " is not an element of the array ";
		print_arr(arr, 6);
		cout << std::endl;
	}

	int arr_in[] = {5, 1, 3};
	int arr_not[] = {6, 5, 8};

	if (is_subset(arr_in, 3, arr, 6))
		print_arr(arr_in, 3);
		cout << " is subset of ";
		print_arr(arr, 6);
		cout << std::endl;
	if (!is_subset(arr_not, 3, arr, 6))
		print_arr(arr_not, 3);
		cout << " is not a subset of ";
		print_arr(arr, 6);
		cout << std::endl;

	return 0;
}
