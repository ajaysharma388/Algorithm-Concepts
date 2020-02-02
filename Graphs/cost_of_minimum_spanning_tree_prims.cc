#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<pair<T,int>>> adjList;
	public:
	// Default Constructor.
	Graph() {}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,int wt,bool bidir = true) {
		this->adjList[u].push_back(make_pair(v,wt));
		if(bidir) {
			this->adjList[v].push_back(make_pair(u,wt));
		}
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			T u = node.first;
			cout << u << " --> ";
			for(auto vertex : node.second) {
				cout << "(" << vertex.first << ", " << vertex.second << ") ";
			}
			cout << endl;
		}
	}
	// Prims Implementation.
	// We are taking a source node src to start with.
	int prims(T src) {
		// creating the visited , parent & distance map.
		map<T,bool> visited;
		map<T,T> parent;
		map<T,int> distance;
		// making the set to keep the lesser always at first.
		set<pair<int,T>> s;
		// Initialise the distance with infinity as we cannot have any
		// path to any of these nodes.
		for(auto node : this->adjList) {
			distance[node.first] = INT_MAX;
		}
		// filling the entries for the source node.
		distance[src] = 0;
		parent[src] = src;
		s.insert({0,src});
		// loop for processing the entire graph.
		while(!s.empty()) {
			// taking the front node into the consideration.
			auto node = *(s.begin());
			T cur_node = node.second;
			int cur_dis = node.first;
			// removing the front node.
			s.erase(s.begin());
			// itrating over current node chidrens.
			for(auto neighbour : this->adjList[cur_node]) {
				if(!visited[neighbour.first] and 
					distance[neighbour.first] > neighbour.second) {
					distance[neighbour.first] = neighbour.second;
					parent[neighbour.first] = cur_node;
					s.insert({neighbour.second,neighbour.first});
				}
			}
			visited[cur_node] = true;
		}
		int cost = 0;
		for(auto node : this->adjList) {
			cost += distance[node.first];
		}
		return cost;
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
	int e;
	cin >> e;
	Graph<char> g;
	for(int edge = 0; edge < e; ++edge) {
		char u,v;
		int w;
		cin >> u >> v >> w;
		g.addEdge(u,v,w);
	}
	g.printAdjList();
	cout << "Cost Of minimum spanning tree is " << g.prims('A') << endl;
	return 0;
}

// Sample Input :

// // 8
// // A B 6
// // A D 2
// // B C 4
// // C D 8
// // D E 3
// // E F 4
// // E G 1
// // F G 2

// Sample Outout :

// A --> (B, 6) (D, 2) 
// B --> (A, 6) (C, 4) 
// C --> (B, 4) (D, 8) 
// D --> (A, 2) (C, 8) (E, 3) 
// E --> (D, 3) (F, 4) (G, 1) 
// F --> (E, 4) (G, 2) 
// G --> (E, 1) (F, 2) 
// Cost Of minimum spanning tree is 18