#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
#define ll long long int
#define endl "\n"

class Edge{
public:
	int src,dest,weight;
};

class Graph{
public:
	int v,e;
	Edge*edges;
	Graph(int v,int e) {
		this->v = v;
		this->e = e;
		this->edges = new Edge[this->v];
	}
	void addEdge(int s,int d,int w,int count){
		this->edges[count].src = s;
		this->edges[count].dest = d;
		this->edges[count].weight = w;  
	}
	void bellmanford(int src) {
		int distance[this->v];
		// initialising the array.
		for(int i = 0; i < this->v; ++i) {
			if(i == src) distance[i] = 0;
			else distance[i] = inf;
		}
		// Relaxation logic.
		for(int i = 1; i < this->v; ++i) {
			for(int j = 0; j < this->e; ++j) {
				int src = this->edges[j].src;
				int dest = this->edges[j].dest;
				int wt = this->edges[j].weight;
				// checking relaxation condition.
				if(distance[dest] > wt + distance[src]) {
					distance[dest] = wt + distance[src];
				}
			}
		}
		for(int j = 0; j < this->e; ++j) {
			int src = this->edges[j].src;
			int dest = this->edges[j].dest;
			int wt = this->edges[j].weight;
			// now if any node updates then it contains the negative edge cycle.
			if(distance[dest] > wt + distance[src]) {
				cout << "The Graph Contains Negative Edge Cycle.";
				return;
			}
		}
		// If there is no cycle in the graph then we have to print distance.
		for(int i = 0; i < this->v; ++i) {
			cout << i << " -> " << distance[i] << endl; 
		}
		return;
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
	int v,e;
	cin >> v >> e;
	Graph g(v,e);
	for(int i = 0; i < e; ++i) {
		int u,v,w;
		cin >> u >> v >> w;
		g.addEdge(u,v,w,i);
	}
	g.bellmanford(0);
	return 0;
}

// Sample Input :

// 5 8
// 0 1 -1
// 0 2 4
// 1 2 3
// 3 2 5
// 4 3 -3
// 1 4 2
// 1 3 2
// 3 1 1

// Sample Output :

// 0 -> 0
// 1 -> -1
// 2 -> 2
// 3 -> -2
// 4 -> 1