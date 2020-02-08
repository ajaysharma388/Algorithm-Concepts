#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Graph {
	ll v;
	list<pair<ll,ll>> *l;
public:
	Graph(ll v) {
		this->v = v;
		this->l = new list<pair<ll,ll>>[this->v];
	}
	void addEdge(ll u,ll v,ll cost,bool bidir = true) {
		this->l[u].push_back(make_pair(v,cost));
		if(bidir) {
			this->l[v].push_back(make_pair(u,cost));
		}
	}
	void printList() {
		for(ll i = 0; i < this->v; ++i) {
			cout << i << " --> " ;
			for(auto node : this->l[i]) {
				cout << "( " << node.first << " ," << node.second << " ) ";
			}
			cout << endl;
		}
	}
	ll dfsHelper(ll node,bool*visited,ll*count,ll &ans) {
		visited[node] = true;
		count[node] = 1;
		// recursively call on the neighbours.
		for(auto neighbour : this->l[node]) {
			ll v = neighbour.first;
			if(!visited[v]) {
				count[node] += dfsHelper(v,visited,count,ans);
				ll s = count[v];
				ll edgeCost = neighbour.second;
				ll n = this->v;
				ans += 2*min(s,n-s)*edgeCost;
			}
		}
		return count[node];
	}
	ll dfs() {
		bool *visited = new bool[this->v];
		ll *count = new ll[this->v];
		for(ll i = 0; i < this->v; ++i) {
			count[i] = 0;
			visited[i] = false;  
		}
		ll ans = 0;
		dfsHelper(0,visited,count,ans);
		return ans;
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
	ll t;
	cin >> t;
	for(ll i = 1; i <= t; ++i) {
		ll n;
		cin >> n;
		Graph g(n);
		for(ll i = 0; i < n-1; ++i) {
			ll u,v,w;
			cin >> u >> v >> w;
			g.addEdge(u-1,v-1,w);
		}
		cout <<"Case #"<< i << ": " << g.dfs() << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 4
// 1 2 3
// 2 3 2
// 4 3 2
// 6
// 1 2 3
// 2 3 4
// 2 4 1
// 4 5 8
// 5 6 5

// Sample Output :

// Case #1: 18
// Case #2: 62