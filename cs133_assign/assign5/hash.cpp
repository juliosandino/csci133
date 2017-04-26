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
		virtual string description() = 0;
};

class str_length : public hash {
	public:
		uint16_t hasher(string str) {	
			uint16_t k = str.length() % MOD;
			return k;
		}

		string description() {
			return "String length";
		}

	
};

class first_char : public hash {
	public:
		uint16_t hasher(string str) {
			uint16_t k = (int) str.at(0);
			return MOD * fmod(k*A, 1);
		}

		string description() {
			return "First char";
		}
};

class checksum : public hash {
	public:
		uint16_t hasher(string str) {
			uint16_t sum = 0;
				for (char c: str)
					sum += (int)c;

			return abs(sum % MOD);
		}

		string description() {
			return "Checksum";
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

		string description() {
			return "Multiplicative";
		}
};

class remainder : public hash {
	public:
		uint16_t hasher(string str) {
			uint16_t sum = 0;
			for (int i = str.size() - 1; i >= 0; i--){
				sum = (sum * 256 + str.at(i)) % 65413;
			}

			return sum;
		}

		string description() {
			return "Remainder";
		}
};

class my_hash : public hash {
	public:
		uint16_t hasher(string str) {
			float pi = .14159265359;
			float ran1 = .9182734756;
			float ran2 = .1325346575;
			uint16_t sum = 0;
			for (int i = 0; i < str.size(); i++) {
				if ( i % 2 == 0)
					sum = fmod(sum + str.at(i) * pi, 1);
				if (i % 2 == 1)
					sum = fmod(sum + str.at(i) * ran1 * ran2, 1);
			}

			return sum * MOD;
		}

		string description() {
			return "Custom Hash";
		}
};
