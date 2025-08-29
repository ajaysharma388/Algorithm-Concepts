#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Graph {
	int V;
	list<int> *l;
public:
	// the constructor.
	Graph(const int V) {
		this->V = V;
		this->l = new list<int>[this->V];
	} 
	// adding the Edge into the graph.
	void addEdge(int u,int v,bool bidir = true) {
		this->l[u].push_back(v);
		if(bidir) {
			this->l[v].push_back(u);
		}
	}
	// printing the adjecency list.
	void printList() {
		for(int i = 0; i < this->V; ++i) {
			cout << i << " --> ";
			for(auto node : this->l[i]) {
				cout << node << ", "; 
			}
			cout << endl;
		}
	}
	bool isBipartite(int src) {
		int *color = new int[this->V];
		for(int i = 0; i < this->V; ++i) {
			color[i] = -1;
		}
		color[src] = 1;
		queue<int> Q;
		Q.push(src);
		// applying the bfs on every node in the graph.
		while(!Q.empty()) {
			int currNode = Q.front();
			Q.pop();
			// iterating over the childrens of currNode.
			for(auto v : this->l[currNode]) {
				if(color[v] == -1) {
					color[v] = 1 - color[currNode];
					Q.push(v);
				} else if (color[v] == color[currNode]) {
					return false;
				}
			}
		}
		return true;
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
	int n,e;
	cin >> n >> e;
	Graph g(n);
	for(int i =0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u-1,v-1);
	}
	if(g.isBipartite(0)) {
		cout << "The Graph is Bipartite." << endl;
	} else {
		cout << "The Graph is not Bipartite." << endl;
	}
	return 0;
}

// Sample Input :

// 4 4
// 1 2
// 2 4
// 3 4
// 1 3

// 4 5
// 1 2
// 2 4
// 3 4
// 1 3
// 1 4

// Sample Output :

// The Graph is Bipartite.
// The Graph is not Bipartite.