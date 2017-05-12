#include "pset.cpp"
#include <vector>
#include <string>

using std::cin;
using std::vector;
using std::string;
using it = vector<string>::iterator;


//checks to see if a string is a number
bool is_num(string s) {
	return (s.at(0) >= '0' && s.at(0) <= '9');
}

//checks to see if a string is an operator "to" or "-" in this case
bool is_op(string s) {
	return (s == "to" || s == "-");
}

//checks to see if the string is a qualifier. "even" or "odd" in this case
bool is_qualifier(string s) {
	return (s == "even" || s == "odd");
}

//function declarations
bool is_expr(it start, it finish);
void parse_pset(it start, it finish);
vector<string> lex(string s);

//This is the global cariable where the regular expressions will get stored
//in the main loop, this expressions will be "evaluated" and printed out to
//the console
vector <pset*> ranges;

int main() {
	string input;

	while (true) {
		//where the tokens will be stored after lexical analysis
		vector<string> tokens;

		cout << "> ";
		std::getline(cin, input);

		//storing the input as tokens
		tokens = lex(input);

		//printing out the tokens to the user
		for (int i = 0; i < tokens.size(); i++)
			cout << "\"" << tokens[i] << "\", ";

		cout << std::endl;

		//checking to see if all the tokens in "tokens" vector are parseable
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

/*
This function is a state machine that takes in an input string and divides
the string into tokens : space, numbers, words, operators.
*/
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

/*
This bad boy over here is the parser.
Due to the linear nature of parsing pages, I can go through the tokens
without any regard of them affecting the tokens that come later.
for example, in "1,2,3,4-8" 1,2,3 will not affect 4-8, so we can parse those
and not worry about them later.

Assumes: Global Vector called ranges.
Modifies the "ranges" vector by adding in the tokens as regular expressions

*/
void parse_pset(it start, it finish) {

	if (start > finish)
		//if input is empty
		return;
	else if (start == finish) {
		//if input is just one token. It has to be a number
		if(is_num(*start))
			ranges.push_back(new pset_num{ stoi(*start) });
	} else {

			//if the tokens follow the grammar <number><operator><number><modifier>
			if (is_num(*start) && is_op(*(start+1)) &&
				is_num(*(start+2)) && is_qualifier(*(start+3))) {

				if (*(start+3) == "odd") {
					ranges.push_back(new pset_r_odd{stoi(*start),
							stoi(*(start+2))});

					//"recursive" call in order to keep looking through the input vector
					parse_pset(start+4, finish);
				}
				else if (*(start+3) == "even") {
					ranges.push_back(new pset_r_even{stoi(*start),
							stoi(*(start+2))});

					parse_pset(start+4, finish);
				}
			}

			//if the tokens follow the grammar <number><operator><number>
			else if (is_num(*start) && is_op(*(start+1)) &&
				is_num(*(start+2))) {
				ranges.push_back(new pset_range{stoi(*start),stoi(*(start+2))});

				parse_pset(start+3, finish);
			}

			//if the tokens follow the grammar <number><expression>+
			else if (is_num(*start)){
			ranges.push_back(new pset_num{ stoi(*start)});

			parse_pset(start+1, finish);
		}
	}

	return;
}

/*
 This function goes through the token vector and makes sure
 all the tokens make valid expressions.
*/
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
