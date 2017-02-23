#include "dlist.h"
typedef dlist::node node;

node* dlist::at(int index) {
	node* c = _head;
	while (index > 0 && c->next) {
		c = c->next;
		index--;
	}

	return c;
}

int dlist::getSize() {
	return size;
}

bool dlist::empty() {
	return size == 0;
}

void dlist::insert(node* previous, int value) {
	node* n = new node{value, previous->next, previous};
	previous->next = n;
	n->next->prev = n; 

	size++;
}

void dlist::push_front(int value){
	node* n = new node{value, _head->next, _head};
	n->prev->next = n;
	n->next->prev = n;
	size++;
}

void dlist::del(node* which) {

	if (which == _head || which == _tail ) {
		std::cout << "Success (Error)\n";
		return;
	}

	node* n = which;
	which->prev->next = n->next;
	which->next->prev = n->prev;
	delete n;

	size--;
}

void dlist::push_back(int value) {
	node* n = new node{value, _tail, _tail->prev};
	_tail->prev->next = n;
	_tail->prev = n;

	size++;
}

void dlist::pop_front() {
	if (size == 0) {
		std::cout << "Success (Error)\n";
		return;
	}
	
	node* n = _head->next;
	_head->next = n->next;	
	n->next->prev = n->prev;

	delete n;
	size--;
}

 void dlist::pop_back() {
	if (size == 0) {
		std::cout << "Success (Error)\n";
		return;
	}

	node* n = _tail->prev;
	_tail->prev = n->prev;
	n->prev->next = _tail;

	delete n;
	size--;
 }

std::ostream& operator<< (std::ostream& out, dlist& l) {
	node* c = l.head()->next;

	while (c != l.tail()) {
		out << c->value;
		out << ",";
		c = c->next;
	}

	out << "\n";
	
	return out;
}

bool operator== (dlist&a, dlist&b) {
	if (a.getSize() != b.getSize()) {
		return false;
	}

	node* c1 = a.head();
	node* c2 = b.head();

	while (c1 != a.tail() && c2 != b.tail()) {
		if (c1->value != c2->value){
			return false;
		}

		c1 = c1->next;
		c2 = c2->next;
	}

	return true;
}

dlist operator+ (dlist&a, dlist&b){
	dlist l;
	node* c = a.head();
	node* d = b.head();

	while (c->next != a.tail()) {
		l.push_back(c->next->value);
		c = c->next;
	}

	while (d->next != b.tail()) {
		l.push_back(d->next->value);
		d = d->next;
	}

	return l;
}

dlist reverse(dlist& l) {
	dlist a;
	node* c = l.head();

	while (c->next != l.tail()) {
		a.push_front(c->next->value);
		c = c->next;
	}

	return a;
}
