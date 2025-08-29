#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<T>> adjList;
public:
	Graph(){}
	// inserting the node into the graph.
	void addEdge(T src,T des,bool bidir = true) {
		this->adjList[src].push_back(des);
		if(bidir) {
			this->adjList[des].push_back(src);
		}
	}
	// printing the Adjacency List.
	void printAdj() {
		for(auto node : this->adjList) {
			cout << node.first << " -> ";
			for(auto vertex : node.second) {
				cout << vertex << ", ";
			}
			cout << endl;
		}
	}
	// recursive function that does DFS traversal on the graph.
	void dfsHelper(T current_city,map<T, bool> &visited) {
		// mark the current city as the visited.
		cout << current_city << " ";
		visited[current_city] = true;
		for(auto city : adjList[current_city]) {
			if(!visited[city]) {
				dfsHelper(city,visited);
			}
		}
	}
	// This Calls the dfsHelper for doing the depth first traversal.
	void DFS(T src) {
		map<T,bool> visited;
		int components = 1;
		dfsHelper(src,visited);
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
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(4,3);
	g.addEdge(3,5);
	g.DFS(0);	
	return 0;
}

// Sample Output :

// 0 1 2 4 3 5 