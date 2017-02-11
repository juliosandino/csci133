#include <iostream>
using std::string;

class Register {
	public:
		//Constructors
		Register();
		Register(string k, int v);
		~Register();

		//accessor methods
		string get_key();
		int get_value();
		bool matches(string k);

		//mutator
		void set_value(int val);
	
	private:
		string key;
		int value;
};
