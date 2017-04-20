#include <vector>
#include <fstream>
#include "hash.cpp"
#include "boost/math/distributions/chi_squared.hpp"

using std::cout;

void tester(hash* function);

int main() {
	
	std::vector<hash*> hashes= {new multiplicative(), 
								new str_length(),
								new first_char(),
								new checksum(),
								new class remainder()};
	for (hash* hash : hashes)
		tester(hash);
	
	return 0;
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
	float c2 = 0;

	for (int i = 0; i < hashes.size(); i++){
		c2 += pow(expected - hashes[i], 2) / expected;
	}

	boost::math::chi_squared c2d(65535.0);
	float p = boost::math::cdf(c2d, c2);
	
	cout << function->description() <<": p = " << p << "\n";
}
