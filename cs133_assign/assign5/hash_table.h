#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class hash_table{
	public:
		void insert(string k, int v);
		int find(string k);

	private:
		std::vector<string> table;
};
