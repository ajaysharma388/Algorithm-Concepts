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
		map<T,int> distance;
		for(auto node : adjList) {
			distance[node.first] = INT_MAX;
		}
		Q.push(src);
		distance[src] = 0;
		while(!Q.empty()) {
			T cur_node = Q.front();
			Q.pop();
			for(auto node : adjList[cur_node]) {
				if(distance[node] == INT_MAX) {
					Q.push(node);
					distance[node] = distance[cur_node] + 1;
				}
			}
		}
		for(auto node : adjList){
			cout << "Distance Of " << node.first << " from " << src << " is " << distance[node.first] << endl;
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

// Sample Output :

// Distance Of 0 from 0 is 0
// Distance Of 1 from 0 is 1
// Distance Of 2 from 0 is 2
// Distance Of 3 from 0 is 2
// Distance Of 4 from 0 is 1