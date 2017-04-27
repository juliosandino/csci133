#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using it = vector<string>::iterator;

vector<string> lex(string s);

struct pset {
		
};

struct pset_to : public pset {
	pset_to (pset* start, pset* finish) {
		this->start = start;
		this->finish = finish;
	}



	pset* start;
	pset* finish;
};

int main() {
	string input;

	while (true) {
		vector<char> chararacters;
		vector<string> tokens;
		cout << "> ";
		std::getline(cin, input);
		//for (char c : input)
		//	chararacters.push_back(c);
		
		tokens = lex(input);
		for (int i = 0; i < tokens.size(); i++)
			cout << "\"" << tokens[i] << "\", ";
		
		tokens.clear();
		cout << std::endl;

	}
}

vector<string> lex(string s) {
	const int SPACE = 0;
	const int NUM = 1;
	const int WORD = 2;
	const int OP = 3;

	int state = SPACE;
	vector<string> words;
	string word;

	for (char c : s) {
		if (state == SPACE) {
			if (c == ' ' || c == ',')
				continue;
			else if (c >= '0' && c <= '9')
				state = NUM;
			else if (c >= 'a' && c <'z')
				state = WORD;
			else if (c == '-')
				state = OP;
		
		word.push_back(c);
		}	

		else {
			//Not in SPACE
			int newstate = state;
			if (c == ' ' || c == ',')
				newstate = SPACE;
			else if (c >= '0' && c <= '9')
				newstate = NUM;
			else if (c >= 'a' && c <= 'z')
				newstate = WORD;
			else if (c == '-')
				newstate = OP;

			if (newstate == SPACE) {
				words.push_back(word);
				word.clear();
				state = SPACE;
				continue;
			}

			if (newstate == state && state !=OP)
				word.push_back(c);
			else if (newstate != state || state == OP) {
				words.push_back(word);
				word.clear();
				word.push_back(c);
			}
			
			state = newstate;
		}

	}

		if (!word.empty())
			words.push_back(word);

		return words;
}
