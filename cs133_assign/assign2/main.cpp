#include "dlist.h"
using std::cout;

int main() {
	dlist l;
	l.push_front(5);
	l.push_front(3);
	l.insert(l.at(1), 6);

	cout << "--previous pointer check--\n";
	if (l.at(1)->prev == l.head()) {
		cout << "Success\n";		
	}

	if (l.at(2)->prev == l.at(1)) {
		cout << "Success\n";		
	}

	if (l.at(3)->prev == l.at(2)) {
		cout << "Success\n";
	}

	if (l.tail()->prev == l.at(3)) {		
		cout << "Success\n";
	}

	cout << "\n";

	cout << "--next pointer check--\n";
	if (l.head()->next == l.at(1)) {
		cout << "Success\n";		
	}

	if (l.at(1)->next == l.at(2)) {
		cout << "Success\n";		
	}

	if (l.at(2)->next == l.at(3)) {
		cout << "Success\n";
	}

	cout << "\n";

	cout << "--deletion check--\n";

	l.del(l.at(3));
	l.del(l.at(1)->prev);

	if (l.at(2)->next == l.tail()){
		cout << "Success\n";
	}

	if (l.tail()->prev == l.at(2)){
		cout << "Success\n";
	}

	cout << "\n";

	cout << "--push_back check--\n";
	
	l.push_back(2);

	if (l.tail()->prev->value == 2) {
		cout << "Success\n";
	}

	if (l.at(2)->next->value == 2) {
		cout << "Success\n";
	}

	cout << "\n";

	cout << "--pop_front check--\n";

	int tmp = l.at(1)->value;
	l.pop_front();

	if (l.at(1)->value != tmp) {
		cout << "Success\n";
	}

	l.pop_front();
	
	if (l.at(1)->value == 2) {
		cout << "Success\n";
	}

	if (l.at(1)->prev == l.head() && l.head()->next == l.at(1)){
		cout << "Success\n";
	}

	l.pop_front();
	l.pop_front();

	cout << "\n";

	cout << "--pop_back--\n";

	l.pop_back();
	l.push_front(2);
	l.push_front(5);

	l.pop_back();

	if (l.tail()->prev->value == 2) {
		cout << "Success\n";
	}

	if (l.at(1)->next == l.tail()) {
		cout <<"Success\n";
	}

	cout << "\n";
	cout << "--list output check--\n";
	cout << l;

	l.push_front(1);
	l.push_back(3);
	l.insert(l.at(2), 4);

	cout << l;

	cout << "\n";

	cout << "--list comparison check--\n";

	dlist b;
	b.push_front(3);
	b.push_front(4);
	b.push_front(5);
	b.push_front(1);
	cout << b;

	if (l == b) {
		cout << "Success (Same)\n";
	}

	b.pop_back();
	b.push_back(5);
	cout << b;

	if (!(l == b)) {
		cout << "Success (Not Same)\n";
	}
	
	cout << "\n";

	cout << "--list concatenation check--\n";
	cout << "adding l and b\n";
	cout << "this is the \"concat\" list\n";
	dlist concat = l + b;
	cout << concat;

	cout << "\n";
	cout << "--reverse check--\n";
	cout << "reversed \"concat\"\n";
	dlist rev = reverse(concat);
	cout << rev;
	return 0;
}
