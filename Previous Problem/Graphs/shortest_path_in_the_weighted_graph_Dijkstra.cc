#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<pair<T,int>>> adjList;
	void printroute(T src,T dest,map<T,T> &parent){
		vector<T> route;
		T temp = dest;
		while(temp != src) {
			route.push_back(temp);
			temp = parent[temp];
		}
		route.push_back(src);
		auto it = route.end()-1;
		for(; it > route.begin()  ; --it) {
			cout << *(it) << " --> ";
		} 
		cout << *(it) << endl;
	}
	public:
	// Default Constructor.
	Graph() {}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,int distance,bool bidir = true) {
		this->adjList[u].push_back(make_pair(v,distance));
		if(bidir) {
			this->adjList[v].push_back(make_pair(u,distance));
		}
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			auto u = node.first;
			cout << u << " --> ";
			for(auto vi : this->adjList[u]) {
				cout << "[" << vi.first << " ," << vi.second << "] ";
			}
			cout << endl;
		}
	}
	// This is the coding inplementation of Dijktras Algorithm.
	void dijktrasSSSP(T src,T dest){
		map<T,int> distance;
		map<T,bool> visited;
		set<pair<int,T>> s;
		map<T,T> parent;
		for(auto node : this->adjList) {
			distance[node.first] = INT_MAX;
		}
		// process the current node.
		parent[src] = src;
		distance[src] = 0;
		s.insert({0,src});
		while(!s.empty()) {
			pair<int,T> cur = *(s.begin());
			T cur_node = cur.second;
			int cur_dis = cur.first;
			// processed all the neighbour of current node.
			for(auto pi : this->adjList[cur_node]) {
				if(!visited[pi.first] and 
					distance[cur_node] + pi.second < distance[pi.first]){
					auto it = s.find({distance[pi.first],pi.first});
					if(it != s.end()){
						// erase the conetent.
						s.erase(it);
					}
					distance[pi.first] = distance[cur_node] + pi.second;
					parent[pi.first] = cur_node;
					s.insert({distance[pi.first],pi.first});
				}		
			}
			// finallize the current node.
			distance[cur_node] = cur_dis;
			visited[cur_node] = true;
			s.erase(s.begin());
		}
		cout << "Minimum Distance Is : " << distance[dest] << endl;
		cout << "Via Route : ";
		printroute(src,dest,parent);
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
	Graph<char> g;
	g.addEdge('a','b',1);
	g.addEdge('a','c',4);
	g.addEdge('a','d',7);
	g.addEdge('b','c',1);
	g.addEdge('c','d',2);
	g.dijktrasSSSP('a','d');
	
	Graph<string> india;
	india.addEdge("Amritsar","Jaipur",4);
	india.addEdge("Amritsar","Delhi",1);
	india.addEdge("Delhi","Jaipur",2);
	india.addEdge("Delhi","Agra",1);
	india.addEdge("Bhopal","Mumbai",3);
	india.addEdge("Agra","Bhopal",2);
	india.addEdge("Mumbai","Jaipur",8);
	india.dijktrasSSSP("Amritsar","Mumbai");
	return 0;
}

// Sample Output :

// Minimum Distance Is : 4
// Via Route : a --> b --> c --> d
// Minimum Distance Is : 7
// Via Route : Amritsar --> Delhi --> Agra --> Bhopal --> Mumbai