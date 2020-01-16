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
	bool cyclicDFSHelper(T node, map<T,bool> &visited, map<T,bool> &inStack) {
		// process the current node;
		visited[node] = true;
		inStack[node] = true;
		for(auto neighbour : this->adjList[node]) {
			if((!visited[neighbour] and cyclicDFSHelper(neighbour,visited,inStack)) or inStack[neighbour]){ 
				return true;
			}
		}
		// mark inStack as false.
		inStack[node] = false;
		return false;
	}
	// iscyclicDfs this is used to detect the cycle int directed graph
	// using Deapth First Search Technique.
	bool cyclicDFS() {
		map<T,bool> inStack;
		map<T,bool> visited;
		for(auto node : this->adjList) {
			T curr_node = node.first;
			if(!visited[curr_node]) {
				bool isCyclic = cyclicDFSHelper(curr_node,visited,inStack);
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
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(1,5,false);
	g.addEdge(2,4,false);
	g.addEdge(2,3,false);
	g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.printAdjList();
	if(g.cyclicDFS()) {
		cout << "Cycle Detected." << endl;
	} else {
		cout << "Cycle Not Detected." << endl;
	}
	return 0;
}