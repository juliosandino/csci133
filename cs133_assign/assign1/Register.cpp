#include "Register.h"

//Destructor
Register::~Register() {};

//Constructor
Register::Register() {
	key = "";
	value = 0;
}

Register::Register(string k, int v) {
	key = k;
	value = v;
}

void Register::set_value(int val) {
	value = val;
}

int Register::get_value() {
	return value;
}

string Register::get_key() {
	return key;
}

bool Register::matches(string k) {
	return key == k;
}
