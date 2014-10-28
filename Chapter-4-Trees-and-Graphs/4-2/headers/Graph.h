#ifndef GRAPH_H
#define GRAPH_H

#include <list>

class Graph{
	int v; // vertices
	std::list<int>* adj; // adjacenies per vertice
	void DFS_Adj(int, bool[]);
	void findPath_Adj(int, int, bool&, bool[]);

	public:
		Graph(int);
		void addEdge(int, int);
		void DFS();
		bool findPath(int, int);

};

Graph::Graph(int n){
	v = n;
	adj = new std::list<int>[n];
}

void Graph::addEdge(int v, int n){
	adj[v].push_back(n);
}

void Graph::DFS_Adj(int v, bool visited[]){

	std::cout << v << " ";

	// Mark the vertice as officially visited
	visited[v] = true;

	// Go through each vertices in adjacency list
	// If vertice has not been visited then print
	std::list<int>::iterator itr;

	for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
		if(!visited[*itr])
			DFS_Adj(*itr, visited);
	}

}

void Graph::DFS(){
	bool * visited = new bool[v];

	// Set all visited to false
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	// Go through each non-visited vertices and find all 
	// connected adjancencies
	for(int i = 0; i < v; i++){
		if(!visited[i]){
			DFS_Adj(i, visited);
			std::cout << std::endl;
		}
	}
}

void Graph::findPath_Adj(int orig, int dest, bool& found, bool visited[]){

	// Set current vertice as visited
	visited[orig] = true;

	// Itreate through all adjacent vertices until match
	// is found
	std::list<int>::iterator itr;

	for(itr = adj[orig].begin(); itr != adj[orig].end(); itr++){

		// Vertice has been unvisisted
		if(!visited[*itr]){
			
			if(*itr == dest){
				found = true;
				return;
			}
			else{
				findPath_Adj(*itr, dest, found, visited);
			}

		}
	}
}

bool Graph::findPath(int orig, int dest){
	bool * visited = new bool[v];
	bool found = false;

	// Set all visited to false
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	if(orig == dest){
		// Special case if findPath asks to find itself
		found = true;
	}
	else{
		// Go through all connected adjacencies to see if
		// theres a connected path
		findPath_Adj(orig, dest, found, visited);
	}
	

	return found;
}

#endif