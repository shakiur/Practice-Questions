#include <iostream>
#include "headers/node.h"

using namespace std;

Node::Node(int d) : data(d) {}

int Node::getData() { return data; }

Node * Node::getNext() { return next; }
