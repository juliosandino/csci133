/*
Created by Julio Sandino
04/15/17
*/

#include <vector>
#include <cstdint>
#include "hash.cpp"
#include <cmath>

using std::vector;
using std::cout;

int main() {
	
	hash h1;
	string test = "Hello";
	vector<int> hashes;

	cout << "Expected: " << test.length() % 65536 << "\n";
	cout << "Result: " << h1.hash_length(test) << "\n";

	cout << "Expected: " << (int) test.at(0) << "\n";
	cout << "Result: " << h1.hash_firstChar(test) << "\n";

	cout << "Expected: 500" << "\n";
	cout << "Result: " << h1.hash_checksum(test) << "\n";

	cout << "Expected: 310939249775" << "\n";
	cout << "Result: " << h1.hash_remainder(test) << "\n";

	return 0;
}
