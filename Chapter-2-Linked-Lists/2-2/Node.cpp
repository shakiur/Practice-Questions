#include <iostream>
#include "headers/Node.h"

// Constructors
Node::Node() : next(NULL) {}
Node::Node(int d) : next(NULL), data(d) {}
Node::Node(int d, Node * n) : next(n), data(d) {} 

// Getters
int Node::getData() { return data; }
Node * Node::getNext() { return next; }

// Setters
void Node::setData(int d) { data = d; }
void Node::setNext(Node* n) { next = n; }