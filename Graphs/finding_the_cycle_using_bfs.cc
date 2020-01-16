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
	// cycle detection using the Breadth First Traversal Technique.
	bool isCyclicBFS(T src) {
		map<T,bool> visited;
		map<T,T> parent;
		queue<T> Q;
		visited[src] = true;
		parent[src] = src;
		Q.push(src);
		while(!Q.empty()) {
			T cur_node = Q.front();
			Q.pop();
			// Traversing it's easy child.
			for(auto neighbour : this->adjList[cur_node]) {
				// if the neighbour is visited and
				// not a parent/ancestor of cur_node.
				// then cycle detected.
				if(visited[neighbour] and parent[cur_node] != neighbour) {
					return true;
				} else if (!visited[neighbour]) {
				// Otherwise mark it visited and set the parent 
				// and push it into the queue. 
					visited[neighbour] = true;
					parent[neighbour] = cur_node;
					Q.push(neighbour);
				}
			}
		}
		// Cycle is not present.
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
	// g.addEdge(4,3);
	g.addEdge(2,3);
	g.printAdjList();
	if(g.isCyclicBFS(1)) {
		cout << "Cycle Detected." << endl;
	} else {
		cout << "Cycle Not Detected." << endl;
	}
	return 0;
}

// Sample Output :

// 1 --> 2, 4, 
// 2 --> 1, 3, 
// 3 --> 2, 
// 4 --> 1, 
// Cycle Not Detected.