#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

vector<ll> routeVa;
vector<ll> routeVb;
vector<ll> routeVc;

template<typename T>
class Graph{
	map<T,list<T>> adjList;
	public:
	// Default Constructor.
	Graph() {}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,bool bidir = true) {
		this->adjList[u].push_back(v);
		if(bidir) {
			this->adjList[v].push_back(u);
		}
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			T u = node.first;
			cout << u << " --> ";
			for(T vertex : this->adjList[u]) {
				cout << vertex << ", ";
			}
			cout << endl;
		}
	}
	// finding the route using bfs.
	void bfsPath(T src,T dest,vector<ll>&route){
		map<T,T> parent;
		map<T,bool> visited;
		queue<T> Q;
		parent[src] = src;
		visited[src] = true;
		Q.push(src);
		while(!Q.empty()) {
			T cur = Q.front();
			Q.pop();
			for(auto node : this->adjList[cur]) {
				if(!visited[node]){
					Q.push(node);
					parent[node] = cur;
					visited[node] = true;
				}				
			}
		}
		T temp = dest;	
		while(temp != src) {
			route.push_back(temp);
			temp = parent[temp];
		}
		route.push_back(src);
		ll n = route.size();
		for(ll i = 0; i < n/2; ++i) {
			swap(route[i],route[n-i-1]);
		}
	}
};

void analyzeRoute(vector<ll> &v,ll*cost) {
	for(ll i = 0; i < v.size()-1; ++i) {
		cost[v[i]]++;
	} 
}

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
		Graph<ll> g;
		ll n;
		cin >> n;
		ll *cost = new ll[n+1]();
		ll a,b,c,va,vb,vc;
		cin >> a >> b >> c >> va >> vb >> vc;
		for(ll i = 1; i < n; ++i) {
			ll u,v;
			cin >> u >> v;
			g.addEdge(u,v);
		}
		g.bfsPath(va,1,routeVa);
		g.bfsPath(vb,1,routeVb);
		g.bfsPath(vc,1,routeVc);
		analyzeRoute(routeVa,cost);
		analyzeRoute(routeVb,cost);
		analyzeRoute(routeVc,cost);
		routeVa.clear();
		routeVb.clear();
		routeVc.clear();
		ll ttlCost = 0;
		// g.printAdjList();
		for(int i = 0; i <= n; ++i) {
			if(cost[i] == 1) ttlCost += a;
			else if(cost[i] == 2) ttlCost += min(a,b);
			else if(cost[i] == 3) ttlCost += min(min(a,b),c);
		}		
		cout << ttlCost << endl;
		delete []cost;
	}
	return 0;
}