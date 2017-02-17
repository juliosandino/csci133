#pragma once
/*
  dlist.h
  Doubly-linked lists of ints
 */
#include <ostream>

class dlist {
  public:
    dlist() { }

    struct node {
        int value;
        node* next;
        node* prev;
    };

    node* head() const { return _head; }
    node* tail() const { return _tail; }

    // **** Implement ALL the following methods ****

    // Returns the node at a particular index (0 is the head).
    node* at(int);

    // Insert a new value, after an existing one
    void insert(node *previous, int value);

    // Delete the given node
    void del(node* which);

    // Add a new element to the *end* of the list
    void push_back(int value);

    // Add a new element to the *beginning* of the list
    void push_front(int value);

    // Remove the first element
    void pop_front();

    // Remove the last element
    void pop_back();

    // Get the size of the list
    int size();

    // Returns true if the list is empty (size == 0)
    bool empty();

  private:
    node* _head = nullptr;
    node* _tail = nullptr;
};

// **** Implement ALL the following functions ****

/* out << l
   Prints a list to the ostream out. This is mostly for your convenience in
   testing your code; it's much easier to figure out what's going on if you
   can easily print out lists!
*/
std::ostream& operator<< (std::ostream& out, dlist& l);

/* a == b
   Compares two lists for equality, returning true if they have the same
   elements in the same positions. (Hint: it is *not* enough to just compare
   pointers! You have to compare the values stored in the nodes.)
*/ 
bool operator== (dlist& a, dlist& b);

/* a + b
   Returns a new list consisting of all the elements of a, followed by all the
   elements of b (i.e., the list concatenation).
*/
dlist operator+ (dlist& a, dlist& b);

/* reverse(l)
   Returns a new list that is the *reversal* of l; that is, a new list 
   containing the same elements as l but in the reverse order.
*/
dlist reverse(dlist& l);