#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Graph{
	int V;
	list<int> *l;
public:
	Graph(const int V){
		this->V = V;
		this->l = new list<int>[this->V];
	}
	// adding edge into the graph.
	void addEdge(int u,int v,bool bidir = true){
		l[u].push_back(v);
		if(bidir) {
			l[v].push_back(u);
		} 
	}
	// printing the Adjacenecy List.
	void printAdjList(){
		for(int i = 0; i < this->V; ++i){
			cout << i << " -> ";
			for(auto vertex : l[i]){
				cout << vertex << ", ";
			}
			cout << endl;
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
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.printAdjList();
	return 0;
}

// Sample Input :

// 0 -> 1, 4, 
// 1 -> 0, 4, 2, 3, 
// 2 -> 1, 3, 
// 3 -> 4, 2, 1, 
// 4 -> 0, 3, 1, 