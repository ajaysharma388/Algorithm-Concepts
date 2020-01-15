#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// This algorithm is often used in linux based enviournment to ensure that
// all the dependencies have been resolved before installing the current package.

// Flutter Doctor from the flutter framework is the latest example of this
// type of dependency resolver.

template<typename T>
class Graph{
	map<T,list<T>> adjList;
public:
	Graph(){}
	// adding the vertex into the graph.
	void addEdge(T u,T v,bool bidir = true) {
		this->adjList[u].push_back(v);
		if(bidir) {
			this->adjList[v].push_back(u);
		}
	}
	// printing the Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			T cur_node = node.first;
			cout << cur_node << " -> ";
			for(auto element : node.second) {
				cout << element << ", ";
			}
			cout << endl;
		}
	}
	// Topological sort using the Breadth First Search Technique.
	void topologicalSortBFS() {
		queue<T> Q;
		map<T,int> indegree;
		map<T,bool> visited;
		// Initialising the data for applying topological sort.
		for(auto i : this->adjList) {
			T current_node = i.first;
			indegree[current_node] = 0;
			visited[current_node] = false;
		}
		// Traversing the map and increasing the indegree.
		for(auto i : this->adjList) {
			T u = i.first;
			for(auto v : this->adjList[u]) {
				indegree[v]++;
			}
		}
		// Find all the nodes with indegree as 0.
		for(auto i : this->adjList) {
			T u = i.first;
			if(indegree[u] == 0) {
				Q.push(u);
			}
		}
		// Algorithm Implementation.
		while(!Q.empty()) {
			T cur_node = Q.front();
			Q.pop();
			cout << cur_node << " --> ";
			for(auto v : this->adjList[cur_node]) {
				indegree[v]--;
				if(indegree[v] == 0) {
					Q.push(v);
				}
			}
		}
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
	Graph<string> g;
	g.addEdge("English","Programming Logic",false);
	g.addEdge("English","Html",false);
	g.addEdge("Maths","Programming Logic",false);
	g.addEdge("Programming Logic","Html",false);
	g.addEdge("Programming Logic","Python",false);
	g.addEdge("Programming Logic","Java",false);
	g.addEdge("Programming Logic","JS",false);
	g.addEdge("Html","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","Web Developement",false);
	g.addEdge("Java","Web Developement",false);
	g.addEdge("Python","Web Developement",false);
	g.topologicalSortBFS();
	return 0;
}

// Sample Output :

// English --> Maths --> Programming Logic --> Html --> Python --> Java --> CSS --> JS --> Web Developement --> 