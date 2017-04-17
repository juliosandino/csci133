#include "hash.h"
#include "cmath"

uint16_t hash::hash_length(string str) {
	return str.length() % hash::size;
}

uint16_t hash::hash_firstChar(string str) {
	return str[0];
}

uint16_t hash::hash_checksum(string str) {
	int sum = 0;

	for (char c : str)
		sum += (int) c;

	return sum % hash::size;
}

long hash::hash_remainder(string str) {
	float k = 0;
	int result = 0;
	float A = 0.6180339887;
	float frac;
	float k_A;

	for (int i = str.length() - 1; i >= 0; i-- )
		k += std::pow(256, str.length() - 1 - i) * str.at(i);

	k_A = k * A;

	frac = k_A;
	std::cout << frac << " " << std::endl;

	result = 10;

	
	return result;
}
	
uint16_t hash::hash_tester( uint16_t hash::*function(string) ,string str) {
	function(str);
	return 0;
};
