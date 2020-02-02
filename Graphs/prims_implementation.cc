#include<bits/stdc++.h>

#define inf 1e9
#define endl "\n"

using namespace std;

class Graph{
	public:
		int v;
		list<pair<int,int>> *adjList;
		Graph(const int v) {
			this->v = v;
			this->adjList = new list<pair<int,int>>[this->v];
		}
		// adding edge into the graph.
		void addEdge(int u,int v,int w) {
			this->adjList[u].push_back(make_pair(v,w));
			this->adjList[v].push_back(make_pair(u,w));
		}
		// method for finding the minimum vertex.
		int findMinVertex(int*weight,bool*visited) {
			int minVertex = -1;
			for(int i = 0; i < this->v; ++i) {
				if(!visited[i] and 
				(minVertex == -1 or weight[i] < weight[minVertex])) {
					minVertex = i;
				}
			}
			return minVertex;
		}
		void prims() {
			// creating the data set that will help us to storing the states.
			bool *visited = new bool[this->v];
			int *weight = new int[this->v];
			int *parent = new int[this->v];
			// initializing the the record we have with defaults.
			for(int i = 0; i < this->v; ++i) {
				visited[i] = false;
				weight[i] = inf;
			}
			parent[0] = -1;
			weight[0] = 0;
			for(int i = 0; i < this->v; ++i) {
				int mVertex = findMinVertex(weight,visited);
				visited[mVertex] = true;
				for(auto neighbour : this->adjList[mVertex]) {
					if(!visited[neighbour.first] and 
					(weight[neighbour.first] > neighbour.second)) {
						parent[neighbour.first] = mVertex;
						weight[neighbour.first] = neighbour.second;
					}
				}
			}
			for(int i = 1; i < this->v; ++i) {
				cout << i << " --> " << parent[i] 
					<< " with weight " << weight[i] << endl;
			}
		}
};

int main() {
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e;
	cin >> v >> e;
	Graph g(v);
	for(int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u,v,w);
	}
	g.prims();
	return 0;
}

// Sample Input :

// 7 8
// 0 3 4
// 0 1 6
// 1 2 5 
// 3 2 7
// 3 4 2
// 4 5 4
// 5 6 1
// 4 6 3

// Sample Output :

// 1 --> 0 with weight 6
// 2 --> 1 with weight 5
// 3 --> 0 with weight 4
// 4 --> 3 with weight 2
// 5 --> 6 with weight 1
// 6 --> 4 with weight 3