#include <vector>
#include <string>
#include <fstream>
#include "hash.cpp"
//#include "boost/math/distributions/chi_squared.hpp"

using std::string;
using std::cout;

static int MOD = 65536;
static double A = 0.6180339887;

void reader();
uint16_t hash_maker(uint16_t k);
float multiplicative_hasher(string str);
void str_length_tester();
void first_char_tester();
void checksum_tester();
void tester(hash* function);

int main() {
	
	std::vector<hash*> hashes= {new multiplicative(), 
								new str_length(),
								new first_char(),
								new checksum()};

	str_length_tester();
	first_char_tester();
	checksum_tester();
	tester(hashes[0]);
	
	return 0;
}

void reader() {
	std::fstream file;
	string line;
	file.open("words.txt");

	if (file.is_open())
		while (getline(file, line))
			cout << line << std::endl;		
}

uint16_t str_length(string str) {
	uint16_t k = str.length() % MOD;
	return MOD * fmod(k*A, 1);
}

uint16_t first_char(string str) {
	return (int) str.at(0);
}

uint16_t checksum(string str) {
	uint16_t sum = 0;
		for (char c: str)
			sum += (int)c;

	return sum;
}

float multiplicative_hasher(string str) {
	float hash = 0;
	
	for (char c: str)
		hash = fmod(256* hash + A * c, 1);

	return hash;
}

uint16_t hash_maker(uint16_t k) {
	return MOD * fmod(k*A, 1);	
}

void str_length_tester() {
	std::vector<int> hashes (65536);
	std::fstream file;
	string line;
	file.open("words.txt");

	if (file.is_open())
		while (getline(file, line))
			hashes[hash_maker(str_length(line))]++;

	float expected = 100000 / 65536;
	float c2;

	for (int i = 0; i < MOD; i++){
		c2 += pow(expected - hashes[i], 2) / expected;
	}

//	boost::math::chi_squared c2d(65535.0);
//	float p = boost::math::cdf(c2d, c2);
	

//	cout << "String length: p = " << p << "\n";
}

void first_char_tester() {
	std::vector<int> hashes (65536);
	std::fstream file;
	string line;
	file.open("words.txt");

	if (file.is_open())
		while (getline(file, line))
			hashes[hash_maker(first_char(line))]++;

	float expected = 100000 / 65536;
	float c2;

	for (int i = 0; i < MOD; i++){
		c2 += pow(expected - hashes[i], 2) / expected;
	}

//	boost::math::chi_squared c2d(65535.0);
//	float p = boost::math::cdf(c2d, c2);
	

//	cout << "First char: p = " << p << "\n";
}


void checksum_tester() {
	std::vector<int> hashes (65536);
	std::fstream file;
	string line;
	file.open("words.txt");

	if (file.is_open())
		while (getline(file, line))
			hashes[hash_maker(checksum(line))]++;

	float expected = 100000 / 65536;
	float c2;

	for (int i = 0; i < MOD; i++){
		c2 += pow(expected - hashes[i], 2) / expected;
	}

//	boost::math::chi_squared c2d(65535.0);
//	float p = boost::math::cdf(c2d, c2);
	

//	cout << "Checksum: p = " << p << "\n";
}

void tester(hash* function) {
	std::vector<int> hashes (65536);
	std::fstream file;
	string line;
	file.open("words.txt");

	if (file.is_open())
		while (getline(file, line))
			hashes[function->hasher(line)]++;

	float expected = 100000 / 65536;
	float c2;

	for (int i = 0; i < MOD; i++){
		c2 += pow(expected - hashes[i], 2) / expected;
	}

//	boost::math::chi_squared c2d(65535.0);
//	float p = boost::math::cdf(c2d, c2);
	

//	cout << "Multiplicative: p = " << p << "\n";
}
