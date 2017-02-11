#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "Register.h"
using std::vector;
using std::cout;
using std::cin;
using std::string;

vector<string> split_words(string input);

Register a ("a", 0);
Register b ("b", 0);
Register c ("c", 0);
Register d ("d", 0);

vector<Register> Registry;

int main() {

	Registry.push_back(a);
	Registry.push_back(b);
	Registry.push_back(c);
	Registry.push_back(d);

	string line;
	vector<string> words;

	while (true) {
		cout << "> ";
		getline(cin, line);
		words = split_words(line);
		if  (words.size() != 0) {

			string command = words.at(0);
		
			if (command == "print") {
				cout << "print";
			} else if (command == "store") {
				cout << "store";
			} else if (command == "add") {
				cout << "add";
			} else if (command == "sub") {
				cout << "sub";
			} else if (command == "mul") {
				cout << "mult";
			} else if (command == "cmp") {
				cout << "comp";
			} else if (command == "stop") {
				break;
			}else {
				cout << "I don't understand that commmand";
			}
		}	
		cout << "\n";
	}

//TEST
//	for (Register r : Registry) {
//		cout << "Key: " << r.get_key() << " Val:" << r.get_value() << "\n";
//	}

	return 0;
}

vector<string> split_words(string input) {
	vector<string> words;
	string current_word;

	std::stringstream in(input);

	while (in >> current_word)
		words.push_back(current_word);

	return words;
}







