#include <string>
#include <iostream>
using std::string;

class hash {
	public:
		uint16_t hash_tester ( uint16_t hash::*function(string), string str );
		uint16_t hash_length(string str);
		uint16_t hash_firstChar(string str);
		uint16_t hash_checksum(string str);
		long hash_remainder(string str);
		
	
	private:
		int size = 65536;
};
