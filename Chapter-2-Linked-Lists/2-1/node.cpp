#include <iostream>
#include "headers/node.h"

using namespace std;

Node::Node(int d) : data(d) {}

Node::Node(int d, Node* n): data(d), next(n) {}

int Node::getData() { return data; }

Node * Node::getNext() { return next; }

void Node::setNext(Node* n) { next = n; }
