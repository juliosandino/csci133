#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <math.h>
#include <fstream>
#include "boost_1_63_0/boost/math/distributions/chi_squared.hpp"

using std::string;
using std::cout;

static int MOD = 65536;

void reader();
uint16_t str_length(string str);
int hash_maker(uint16_t k);
void tester();

int main() {

	tester();
	
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
	return str.length() % MOD;
}

int hash_maker(uint16_t k) {
	double A = 0.6180339887;
	return MOD * fmod(k*A, 1);
}

void tester() {
	std::vector<int> hashes (65536);
	std::fstream file;
	string line;
	file.open("words.txt");

	if (file.is_open())
		while (getline(file, line))
			hashes[hash_maker(str_length(line))]++;

//	for (int i = 0; i < MOD; i++)
//		if (hashes[i] > 0)
//			cout << i << ": " << hashes[i] << "\n";
	
	float expected = 100000 / 65536;
	float c2;

	for (int i = 0; i < MOD; i++) {
		c2 += pow(expected - hashes[i], 2) / expected;
	}
	
	double c2d;

}
