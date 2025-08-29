#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<T>> adjList;
	public:
	// Default Constructor.
	Graph() {}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,bool bidir = true) {
		this->adjList[u].push_back(v);
		if(bidir) {
			this->adjList[v].push_back(u);
		}
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			T u = node.first;
			cout << u << " --> ";
			for(T vertex : this->adjList[u]) {
				cout << vertex << ", ";
			}
			cout << endl;
		}
	}
	bool cyclicDFSHelper(T node, map<T,bool> &visited, T parent) {
		// mark the current node as 
		visited[node] = true;
		// traverse it's childrens one by one.
		for(auto neighbour : this->adjList[node]) {
			if(!visited[neighbour]) {
				// checking if the current neighbour has any cycle.
				bool isCyclic = cyclicDFSHelper(neighbour,visited,node);
				if(isCyclic) return true;
			} else if(neighbour != parent) {
				// if the neighbour is already visited and not a parent.
				return true;
			}
		}
		// no cycle exist.
		return false;
	}
	// iscyclicDfs this is used to detect the cycle int directed graph
	// using Deapth First Search Technique.
	bool cyclicDFS() {
		map<T,bool> visited;
		for(auto node : this->adjList) {
			T curr_node = node.first;
			if(!visited[curr_node]) {
				bool isCyclic = cyclicDFSHelper(curr_node,visited,curr_node);
				if(isCyclic) return true;
			}
		}
		return false; 
	}
};

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph<int> g;
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	// g.addEdge(4,3);
	g.printAdjList();
	if(g.cyclicDFS()) {
		cout << "Cycle Detected." << endl;
	} else {
		cout << "Cycle Not Detected." << endl;
	}
	return 0;
}

// Sample Output :

// 1 --> 2, 4, 
// 2 --> 1, 3, 
// 3 --> 2, 4, 
// 4 --> 1, 3, 
// Cycle Detected.

// comment line 75 for this Output.

// 1 --> 2, 4, 
// 2 --> 1, 3, 
// 3 --> 2, 
// 4 --> 1, 
// Cycle Not Detected.