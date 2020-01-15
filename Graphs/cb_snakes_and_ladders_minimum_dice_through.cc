#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// Define the class.
template<typename T>
class Graph{
	map<T,list<T>> adjList;
public:
	Graph(){}
	// Adding the Edge Into The Graph.
	void addEdge(T u,T v,bool bidir = true){
		this->adjList[u].push_back(v);
		if(bidir) {
			this->adjList[v].push_back(u);
		}
	}
	// printing the adjacency List.
	void printAdjList(){ 
		for(auto node : this->adjList) {
			T u = node.first;
			cout << u << " --> ";
			for(auto v : this->adjList[u]) {
				cout << v << ", ";
			}
			cout << endl;
		}
	}
	int BFS(T src,T dest) {
		map<T,bool> visited;
		map<T,int> distance;
		queue<T> Q;
		Q.push(src);
		visited[src] = true;
		distance[src] = 0;
		while(!Q.empty()) {
			T curr_node = Q.front();
			Q.pop();
			for(auto node : this->adjList[curr_node]) {
				if(!visited[node]) {
					distance[node] = 1 + distance[curr_node];
					visited[node] = true;
					Q.push(node);
				}
			}
		}
		return distance[dest];
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
	int t;
	cin >> t;
	while(t--) {
		Graph<int> g;
		int n,la,sn;
		cin >> n >> la >> sn;
		int*board = new int[n+1]();
		for(int i = 1; i <= la; ++i) {
			int s,e;
			cin >> s >> e;
			board[s] = e-s;
		}
		for(int i = 1; i <= sn; ++i) {
			int s,e;
			cin >> s >> e;
			board[s] = e-s;
		}
		for(int u = 0; u <= n; ++u) {
			for(int dice = 1; dice <= 6; ++dice) {
				int v = u + dice + board[u + dice];
				g.addEdge(u,v,false);
			}
		}
		cout << g.BFS(1,n) << endl;
	}
	return 0;
}

// Sample Input :

// 1
// 30 4 4
// 3 22
// 5 8
// 11 26
// 20 29
// 17 4
// 19 7
// 21 9
// 27 1

// Sample Output :

// 3