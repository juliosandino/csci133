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
	virtual void evaluate() = 0;
};

struct pset_num : public pset {
	pset_num (int value) {
		v = value;
	}
	
	void evaluate() {
		cout << v << ", ";
	}

	int v;
};

struct pset_range : public pset {
	pset_range(int start, int end) {
		s = start;
		e = end;
	}

	void evaluate() {
		for (int i = s; i <= e; i++) {
			cout << i << ", ";
		}
	}

	int s;
	int e;
};

struct pset_r_odd : public pset {
	pset_r_odd(int start, int end) {
		s = start;
		e = end;
	}

	void evaluate() {
		for (int i = s; i <= e; i++) {
			if (i % 2 == 1)
				cout << i << ", ";
		}
	}

	int s;
	int e;
};

struct pset_r_even : public pset {
	pset_r_even(int start, int end) {
		s = start;
		e = end;
	}

	void evaluate() {
		for (int i = s; i <= e; i++) {
			if (i % 2 == 0)
				cout << i << ", ";
		}
	}

	int s;
	int e;
};

bool is_num(string s) {
	return (s.at(0) >= '0' && s.at(0) <= '9');
}

bool is_op(string s) {
	return (s == "to" || s == "-");
}

bool is_qualifier(string s) {
	return (s == "even" || s == "odd");
}

bool is_expr(it start, it finish);
void parse_pset(it start, it finish);
vector <pset*> ranges;

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

		cout << std::endl;

		bool valid = is_expr(tokens.begin(), tokens.end() -1);

		if (valid) {
			cout << "Valid!" << std::endl;
			parse_pset(tokens.begin(), tokens.end() -1);
			for (pset* exp : ranges) {
				exp->evaluate();
			}	
			ranges.clear();
		
		} else {
			cout << "Invalid input" << std::endl;
		}
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

void parse_pset(it start, it finish) {

	if (start > finish)
		return;
	else if (start == finish) {
		if(is_num(*start))
			ranges.push_back(new pset_num{ stoi(*start) });
	} else {
			if (is_num(*start) && is_op(*(start+1)) &&
				is_num(*(start+2)) && is_qualifier(*(start+3))) {
				if (*(start+3) == "odd") {
					ranges.push_back(new pset_r_odd{stoi(*start),
							stoi(*(start+2))});
				
					parse_pset(start+4, finish);
				}
				else if (*(start+3) == "even") {
					ranges.push_back(new pset_r_even{stoi(*start),
							stoi(*(start+2))});

					parse_pset(start+4, finish);
				}
			}	
			
			else if (is_num(*start) && is_op(*(start+1)) &&
				is_num(*(start+2))) {
				ranges.push_back(new pset_range{stoi(*start),stoi(*(start+2))});

				parse_pset(start+3, finish);
			}

		   else if (is_num(*start)){
			ranges.push_back(new pset_num{ stoi(*start)});
			
			parse_pset(start+1, finish);
		}
	}

	return;
}

bool is_expr(it start, it finish) {
	if (start > finish)
		return true;
	else if (start == finish) {
		if(is_num(*start))
			return true;
		else
			return false;
	}
	else {
		if (is_num(*start) && is_op(*(start+1)) &&
				is_num(*(start+2)) && is_qualifier(*(start+3))) {
			return is_expr(start+4, finish);
		} else if (is_num(*start) && is_op(*(start+1)) &&
				is_num(*(start+2))) {
			return is_expr(start+3, finish);
		} else if (is_num(*start)) {
			return is_expr(start+1, finish);
		}
		
	}

	return false;
}
