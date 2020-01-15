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
		cout << current_city << ", ";
		visited[current_city] = true;
		for(auto city : adjList[current_city]) {
			if(!visited[city]) {
				dfsHelper(city,visited);
			}
		}
	}

	int DFS(T src) {
		map<T,bool> visited;
		int components = 1;
		cout << "Component #" << components << " : ";
		dfsHelper(src,visited);
		cout << endl;
		for(auto node : this->adjList) {
			T city = node.first;
			if(!visited[city]) {
				components++;
				cout << "Component #" << components << " : ";
				dfsHelper(city,visited);
				cout << endl;
			}
		}
		return components;
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
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Mumbai","Jaipur");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Mumbai","Bangalore");
	g.addEdge("Agra","Delhi");
	g.addEdge("Andamaan","Nicobar");
	int cc = g.DFS("Amritsar");
	cout << "The number of connected components in Graph are " << cc << "." << endl;	
	return 0;
}

// Sample Output :

// Component #1 : Amritsar, Jaipur, Delhi, Bhopal, Mumbai, Bangalore, Agra, 
// Component #2 : Andamaan, Nicobar, 
// The number of connected components in Graph are 2. 