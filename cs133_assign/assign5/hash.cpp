#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
using std::string;


class hash {
	public:
		int MOD = 65535;
		float A = 0.6180339887;
		virtual uint16_t hasher(string str) = 0;
};

class str_length : public hash {
	public:
		uint16_t hasher(string str) {	
			uint16_t k = str.length() % MOD;
			return MOD * fmod(k*A, 1);
		}
};

class first_char : public hash {
	public:
		uint16_t hasher(string str) {
			uint16_t k = (int) str.at(0);
			return MOD * fmod(k*A, 1);
		}
};

class checksum : public hash {
	public:
		uint16_t hasher(string str) {
			uint16_t sum = 0;
				for (char c: str)
					sum += (int)c;

			return MOD * fmod(sum * A, 1);
		}
};

class multiplicative : public hash {
	public:
		uint16_t hasher(string str) {	
			float hash = 0;
			
			for (char c: str)
				hash = fmod(256* hash + A * c, 1);

			return hash;
		}
};
