/*
Given a directed graph, design an algorithm to find out whether there
is a route between two nodes
*/

#include <iostream>
#include "headers/Graph.h"

int main(){
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	//g.addEdge(1, 3);
	g.addEdge(2, 0);
	g.addEdge(2, 1);
	//g.addEdge(3, 1);

	g.DFS();

	int orig = 0;
	int dest = 3;

	if(g.findPath(orig, dest))
		std::cout << "Path exists between " << orig << " and " << dest << std::endl;
	else
		std::cout << "Path DOES NOT exist between " << orig << " and " << dest << std::endl;

}