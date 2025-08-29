#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<T>> adjList;
public:
	Graph(){}
	// Function To add the nodes into the graph.
	void addEdge(T src,T des,bool bidir = true){
		adjList[src].push_back(des);
		if(bidir){
			adjList[des].push_back(src);
		}
	}
	// Printing the adjecency List.
	void printAdjList(){
		for(auto src : adjList) {
			cout << src.first << " -> ";
			for(auto des : src.second) {
				cout << des << ", ";
			}
			cout << endl;
		}
	}
	// Traversing the graph using B.F.S Technique.
	void BFS(T src){
		queue<T> Q;
		map<T,bool> visited;
		Q.push(src);
		visited[src] = true;
		while(!Q.empty()) {
			T cur_node = Q.front();
			Q.pop();
			cout << cur_node << " ";
			for(auto node : adjList[cur_node]) {
				if(!visited[node]) {
					Q.push(node);
					visited[node] = true;
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
	Graph<int> ga;
	ga.addEdge(0,1);
	ga.addEdge(0,4);
	ga.addEdge(4,3);
	ga.addEdge(1,4);
	ga.addEdge(1,2);
	ga.addEdge(2,3);
	ga.addEdge(1,3);
	ga.BFS(0);
	return 0;
}

// Sample Outout :

// 0 1 4 2 3 