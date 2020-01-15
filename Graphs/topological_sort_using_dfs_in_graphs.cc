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
	// dfshelper for doing topological sorting.
	void dfshelper(T cur_node,map<T, bool> &visited,list<T> &ordering) {
		// mark current node as the visited.
		visited[cur_node] = true;
		// travelling down into it's unvisited childrens.
		for(auto node : this->adjList[cur_node]) {
			if(!visited[node]) {
				dfshelper(node,visited,ordering);
			}
		}
		// all the child nodes of the cur_node are processed 
		// now we will process the current node now.
		ordering.push_front(cur_node);
	} 
	// dfs funtion to sort the graph topologically.
	void dfsTopological() {
		map<T,bool> visited;
		list<T> ordering;
		for(auto node : this->adjList) {
			T cur_node = node.first;
			if(!visited[cur_node]) {
				dfshelper(cur_node,visited,ordering);
			}
		}
		// print the data of the ordering.
		for(auto element : ordering) {
			cout << element << " -> ";
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
	g.dfsTopological();
	return 0;
}

// Sample Output :

// Maths -> English -> Programming Logic -> Java -> Python -> Html -> CSS -> JS -> Web Developement -> 