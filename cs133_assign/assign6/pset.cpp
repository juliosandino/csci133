#include <iostream>
using std::cout;

//the evaluate function just print outs to the console
//the individual pages that need to be printed out.
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
