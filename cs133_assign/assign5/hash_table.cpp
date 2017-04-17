#include "hash_table.h"

void hash_table::insert(string k, int v) {
	if (table[v] == "")
		return;
	else
		table[v] = k;
}

int hash_table::find(string k) {
	int index = 0;
	//hash the string
	//hash(k)
	//set index equal to the hash
	return index;
}
