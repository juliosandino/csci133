/*
  main.cpp
  This is the file where the main function runs

  Julio Sandino
  Changelog:
	Feb-10 first submission
	Feb-14 resubmission:
		Implented all the functions needed.
		Used a vector that holds Register object pointers.
		Added error control.


  So far, whats been implemented is a class of a register which
  holds a key and a value. Also the program recognizes the commands
  but the commands have not been implemented. To be honest I thought
  I'd have til 11:59 pm to submit the work, but boy was I wrong.
  The program uses functionality from c++11 to check if a string is all numbers
  so in order for it to compile use g++ std=c++11...
*/

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Register.h"
using std::vector;
using std::cout;
using std::cin;
using std::string;

vector<string> split_words(string input);
void print (string key);
void store (string key, int val);
void add (string k1, string k2, string k3);
void sub (string k1, string k2, string k3);
void mul (string k1, string k2, string k3);
void cmp (string k1, string k2, string k3);
int string_to_int(string s);
Register* find_register(string key);

/*
Register* a ("a", 0);
Register* b ("b", 0);
Register* c ("c", 0);
Register* d ("d", 0);
*/

vector<Register*> Registry;
string const arg_error = "insufficient amount of arguments\n";
bool is_number(const string& s);

int main() {

	Registry.push_back( new Register("a", 0));
	Registry.push_back( new Register("b", 0));
	Registry.push_back( new Register("c", 0));
	Registry.push_back( new Register("d", 0));

	string line;
	vector<string> words;

	while (true) {
		cout << "> ";
		getline(cin, line);
		words = split_words(line);
		if  (words.size() != 0) {

			string command = words.at(0);
		
			if (command == "print") {

				if (words.size() > 1) {
					string key = words.at(1);
					print (key);
				} else {
					cout << arg_error;
				}
				
			} else if (command == "store") {

				Register* reg;
				int value;
				
				if (words.size() > 2) {
					try {
					 string val = words.at(1);
					 string key = words.at(2);
					
					 bool neg = val.at(0) == '-';
					 
					 if (neg)
						 val = val.substr(1, val.length());

					 if (!is_number(val)) {
						reg = find_register(val);
						if (reg == nullptr) {
							throw val;
						}

						value = reg->get_value();
					 } else {
						 if (!neg)
							value = std::stoi(val);
						 else
							value = 0 - std::stoi(val);
					 }
					 
					 store (key, value);
					} catch (string e) {
						cout << words.at(1) << " is not a storable value\n";
					}
				} else {
					cout << arg_error;
				}

			} else if (command == "add") {

				if (words.size() > 3) {
					string k1 = words.at(1);
					string k2 = words.at(2);
					string k3 = words.at(3);

					add (k1, k2, k3);
				} else {
					cout << arg_error;
				} 
			} else if (command == "sub") {
				
				if (words.size() > 3) {
					string k1 = words.at(1);
					string k2 = words.at(2);
					string k3 = words.at(3);

					sub (k1, k2, k3);
				} else {
					cout << arg_error;
				}
			
			} else if (command == "mul") {
				
				if (words.size() > 3) {
					string k1 = words.at(1);
					string k2 = words.at(2);
					string k3 = words.at(3);

					mul (k1, k2, k3);
				} else {
					cout << arg_error;
				}

			} else if (command == "cmp") {
				
				if (words.size() > 3) {
					string k1 = words.at(1);
					string k2 = words.at(2);
					string k3 = words.at(3);

					cmp (k1, k2, k3);
				} else {
					cout << arg_error;
				}

			} else if (command == "stop") {
				break;
			} else {
				cout << "I don't understand that commmand\n";
			}
		}	
	}

	return 0;
}

/*
  This is the function you implemented in class.
  I thought that it was pretty good so I used it
  on this assigment.
  
  Source: Class
  Author: Professor Clifton
*/
vector<string> split_words(string input) {
	vector<string> words;
	string current_word;

	std::stringstream in(input);

	while (in >> current_word)
		words.push_back(current_word);

	return words;
}

/*
 find_register(string key)
 It returns a Register pointer to the Global Registry array where
 the string key equals the key of that Register.

 - key: the string used to match with the key of the Register object

 Returns: a pointer to the Registry

 Assumes: Global Variable Registry 
 Ensures: Registry will still remain unchanged and so will "key"
 */
Register* find_register(string key) {
	int counter = 0;

	for (Register* k : Registry) {
		if (k->matches(key)) {
			return k;
			counter++;
		}
	}

	return nullptr;
}

/*
 print (string key)
 It prints the value of the Register to the console

 - key: the string is used to match the key of the Register object

 Assumes: Global Variable Registry
 
 Ensures: Registry will remain unchanged and so will "key"
 */
void print (string key) {
	Register* target = find_register(key);
	
	if (target)
		cout << target->get_value() << "\n";
	else
		cout << "sorry that registry doesn't exist\n";
}

/*
 store(string key, int val)
 this will store a value in one of the Registers in the Registry vector

 - key: The string is used to match the key of the Register Object
 - value: The integer value that will be stored in the Regiser Object

 Assumes: Global Variable Registry

 Ensures: An object in the Registry Vector will have its value changed
 */
void store (string key, int val) {
	Register* target = find_register(key);

	if (target) {
		target->set_value(val);
	} else {
		cout << "sorry that registry doesn't exist\n";
	}
}

/*
 add (string k1, string k2, string k3)
 this adds two register values and stores them in a third one

 - k1: used to match the registry 

 - k1: string used to match the key of the Register object that will be added
 - k2: string used to match the key of the Register object that will be added
 - k3: string used to match the key of the Register object that will store the		 added values

 Assumes: Global Variable Registry

 Ensures: k1 and k2 will not be changed. k3's value will change
 */
void add (string k1, string k2, string k3) {
	int value1;
	int value2;
	int int_key1;
	int int_key2;
	Register* register_key1;
	Register* register_key2;
	Register* key3 = find_register(k3);

	try {
		value1 = std::stoi(k1);
	} catch (std::invalid_argument e) {
		register_key1 = find_register(k1);
		if (register_key1) {
			value1 = register_key1->get_value();
		} else {
			cout << k1 << " is not a valid registry\n";
			return;
		}
	}

	try {
		value2 = std::stoi(k2);
	} catch (std::invalid_argument e) {
		register_key2 = find_register(k2);
		if (register_key2) {
			value2 = register_key2->get_value();
		} else {
			cout << k2 << " is not a valid registry\n";
			return;
		}
	}

	if (value1 && value2 && key3) {
		int sum = value1 + value2;
		key3->set_value(sum);
	} else {
		cout << "one of the registries does not exist\n";
	}
}

/*
 sub (string k1, string k2, string k3)
 subtracts a registries value from another and stores them in a third one

 - k1: string used to match the key of the Register object that will be substracted
 - k2: string used to match the key of the Register object that will be substracted
 - k3: string used to match the key of the Register object that will store the		 added values

 Assumes: Global Variable Registry

 Ensures: k1 and k2 will not be changed. k3's value will change
 */
void sub (string k1, string k2, string k3) {	
	int value1;
	int value2;
	int int_key1;
	int int_key2;
	Register* register_key1;
	Register* register_key2;
	Register* key3 = find_register(k3);

	try {
		value1 = std::stoi(k1);
	} catch (std::invalid_argument e) {
		register_key1 = find_register(k1);
		if (register_key1) {
			value1 = register_key1->get_value();
		} else {
			cout << k1 << " is not a valid registry\n";
			return;
		}
	}

	try {
		value2 = std::stoi(k2);
	} catch (std::invalid_argument e) {
		register_key2 = find_register(k2);
		if (register_key2) {
			value2 = register_key2->get_value();
		} else {
			cout << k2 << " is not a valid registry\n";
			return;
		}
	}

	if (value1 && value2 && key3) {
		int sum = value1 - value2;
		key3->set_value(sum);
	} else {
		cout << "one of the registries does not exist\n";
	}
}

/*
 mul (string k1, string k2, string k3)
 multiplies a registries value by another and stores them in a third one

 - k1: string used to match the key of the Register object that will be multiplied
 - k2: string used to match the key of the Register object that will be multiplied
 - k3: string used to match the key of the Register object that will store the		 multiplied values

 Assumes: Global Variable Registry

 Ensures: k1 and k2 will not be changed. k3's value will change
 */
void mul (string k1, string k2, string k3) {
	int value1;
	int value2;
	int int_key1;
	int int_key2;
	Register* register_key1;
	Register* register_key2;
	Register* key3 = find_register(k3);

	try {
		value1 = std::stoi(k1);
	} catch (std::invalid_argument e) {
		register_key1 = find_register(k1);
		if (register_key1) {
			value1 = register_key1->get_value();
		} else {
			cout << k1 << " is not a valid registry\n";
			return;
		}
	}

	try {
		value2 = std::stoi(k2);
	} catch (std::invalid_argument e) {
		register_key2 = find_register(k2);
		if (register_key2) {
			value2 = register_key2->get_value();
		} else {
			cout << k2 << " is not a valid registry\n";
			return;
		}
	}

	if (value1 && value2 && key3) {
		int sum = value1 * value2;
		key3->set_value(sum);
	} else {
		cout << "one of the registries does not exist\n";
	}
}

/*
 mul (string k1, string k2, string k3)
 compares a registry value to another and stores them in a third one

 - k1: string used to match the key of the Register object that will be compared
 - k2: string used to match the key of the Register object that will be compared
 - k3: string used to match the key of the Register object that will store the		 comparison value (-1, 0, or 1)

 Assumes: Global Variable Registry

 Ensures: k1 and k2 will not be changed. k3's value will change
 */
void cmp (string k1, string k2, string k3) {
	Register* key1 = find_register(k1);
	Register* key2 = find_register(k2);
	Register* key3 = find_register(k3);

	if (key1 && key2 && key3) {
		int a = key1->get_value();
		int b = key2->get_value();
		int result;
		if (a == b){
			result = 0;
		} else if (a > b) {
			result = 1;	
		} else {
			result = -1;
		}

		key3->set_value(result);
	} else {
		cout << "one of the registries does not exist\n";
	}
}

/*
 is_number (const string& s)
 checks if a string is exclusively only numbers.
 string& s: string that will be checked to see if its a positive integer

 Returns true if the string constains only numbers
 Credit: I got this function from stackoverflow

 Depends: <Algorithm>
 }
 */
bool is_number (const string& s){
	return !s.empty() && std::find_if(s.begin(),
			s.end(), [](char c) { return !std::isdigit(c);}) == s.end();
}

int string_to_int(string s) {
	bool neg = s.at(0) == '-';

	if (neg)
		s = s.substr(1, s.length());

	if (!is_number(s))
		throw s;

	int value;

	if (!neg)
		value = std::stoi(s);
	else
		value = 0 - std::stoi(s);

	return value;
}
