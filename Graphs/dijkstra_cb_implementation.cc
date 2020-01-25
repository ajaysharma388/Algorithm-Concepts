#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<pair<T,int>>> adjList;
	void print_route(map<T,T> &parent,T src,T dest) {
		T temp = dest;
		vector<T> route;
		while(temp!=src) {
			route.push_back(temp);
			temp = parent[temp];
		}
		route.push_back(src);
		int n = route.size();
		for(int i = 0; i < n/2; ++i) {
			swap(route[i],route[n-i-1]);
		}
		int i = 0;
		for(; i < n-1; ++i) {
			cout << route[i] << " -> ";
		}
		cout << route[i] << endl;
	}
public:
	Graph() {}	void push_node(T u,T v,int distance,bool bidir = true) {
		this->adjList[u].push_back({v,distance});
		if(bidir) {
			this->adjList[v].push_back({u,distance});
		}
	}
	// printing the adjacency list.
	void printList() {
		for(auto j : this->adjList) {
			cout << j.first << " -> ";
			for(auto li : j.second) {
				cout << "[" <<li.first << " ," << li.second << " ] "; 
			}
			cout << endl;
		}
	}
	// DijkstraSSSP finds the sorted path in the graph from single
	// source shored path.
	void DijkstraSSSP(T src,T dest) {
		map<T,T> parent;
		map<T,int> distance;
		// initialize all the elements with infity.
		for(auto node : this->adjList) {
			T city = node.first;
			distance[city] = INT_MAX;
		}
		// Make a set to find out the node with the minimum distance.
		set<pair<int,T>> s;
		distance[src] = 0;
		parent[src] = src;
		s.insert({0,src});
		while(!s.empty()) {
			// Extracting the first element with shortest possible distance.
			auto cur_node = *(s.begin());
			// city name and distance of cur_node from src.
			T cur_city = cur_node.second;
			int cur_dis = cur_node.first;
			s.erase(s.begin());
			for(auto neighbour : this->adjList[cur_city]) {
				// If the distance of the neighbour through current node is smaller
				// than the distance distance of neighbour from the src then update it.
				if(cur_dis + neighbour.second < distance[neighbour.first]) {
					// Since set data structure does not support the update feature
					// so, to take care of that we have to remove the old pair and insert
					// the new pair into the set to mimic the updatation.
					auto des = neighbour.first;
					auto it = s.find({distance[des],des});
					if(it != s.end()) {
						s.erase(it);
					}
					distance[neighbour.first] = cur_dis + neighbour.second;
					parent[neighbour.first] = cur_city;
					s.insert({distance[neighbour.first],neighbour.first});
				} 
			}
		}
		print_route(parent,src,dest);
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
	Graph<string> india;
	india.push_node("Amritsar","Delhi",1);
	india.push_node("Amritsar","Jaipur",4);
	india.push_node("Jaipur","Delhi",2);
	india.push_node("Jaipur","Mumbai",8);
	india.push_node("Bhopal","Agra",2);
	india.push_node("Mumbai","Bhopal",3);
	india.push_node("Agra","Delhi",1);
	// india.printList();
	india.DijkstraSSSP("Mumbai","Amritsar");
	return 0;
}

// Sample Output :

// Mumbai -> Bhopal -> Agra -> Delhi -> Amrit