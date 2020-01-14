#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T ,list<T>> adjList;
public:
	// since map is dynamic so we will not need constructor.
	Graph(){}
	// adding edge into the graph.
	void addEdge(T u,T v,bool bidir = true){
		adjList[u].push_back(v);
		if(bidir) {
			adjList[v].push_back(u);
		} 
	}
	// printing the Adjacenecy List.
	void printAdjList(){
		for(auto obj : adjList){
			cout << obj.first << " -> ";
			for(auto vertex : obj.second){
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
	Graph<int> ga;
	ga.addEdge(0,1);
	ga.addEdge(0,4);
	ga.addEdge(4,3);
	ga.addEdge(1,4);
	ga.addEdge(1,2);
	ga.addEdge(2,3);
	ga.addEdge(1,3);
	ga.printAdjList();
	Graph<string> gb;
	gb.addEdge("Rahul","Ajay");
	gb.addEdge("Modi","Ajay",false);
	gb.addEdge("Vijay","Ajay");
	gb.addEdge("Yogi","Ajay",false);
	gb.addEdge("Trump","Ajay",false);
	gb.addEdge("Trump","Rahul");
	gb.addEdge("Putin","Rahul");
	gb.addEdge("Ajay","Putin");
	gb.printAdjList();
	return 0;
}

// Sample Output :

// 0 -> 1, 4, 
// 1 -> 0, 4, 2, 3, 
// 2 -> 1, 3, 
// 3 -> 4, 2, 1, 
// 4 -> 0, 3, 1, 

// Ajay -> Rahul, Vijay, Putin, 
// Modi -> Ajay, 
// Putin -> Rahul, Ajay, 
// Rahul -> Ajay, Trump, Putin, 
// Trump -> Ajay, Rahul, 
// Vijay -> Ajay, 
// Yogi -> Ajay, 