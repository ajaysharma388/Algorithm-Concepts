#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	map<T,list<T>> adjList;
public:
	// we don't need to do anything here in constructor.
	// as map is dynamic Data Structure.
	Graph(){}
	// Adding the Edge into the Graph between Two Nodes.
	void addEdge(T src,T des,bool bidir = true){
		this->adjList[src].push_back(des);
		if(bidir){
			this->adjList[des].push_back(src);
		}
	}

	T BFS(T src,T dest){
		vector<T> route;
		queue<T> Q;
		map<T,int> distance;
		map<T,T> parent;
		for(auto obj : adjList) {
			distance[obj.first] = INT_MAX;
		}
		Q.push(src);
		distance[src] = 0;
		parent[src] = src;
		while(!Q.empty()) {
			T curr = Q.front();
			Q.pop();
			for(T obj : this->adjList[curr]) {
				if(distance[obj] == INT_MAX) {
					parent[obj] = curr;
					Q.push(obj);
					distance[obj] = distance[curr] + 1;
				}
			}
		}
		T temp = dest;
		while(temp != src){
			route.push_back(temp);
			temp = parent[temp];
		}
		cout << "sortest route will be." << endl; 
		cout << src ;
		for(auto it = route.end(); it > route.begin(); --it){
			cout << " -> " << *(it-1); 
		}
		return distance[dest];
	}

	// printing the adjecency List.
	void printAdjList(){
		for(auto obj : this->adjList){
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
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
	for(int u = 0; u <= 36; ++u){
		for(int dice = 1; dice <= 6; ++dice){
			int v = u + dice + board[u + dice];
			ga.addEdge(u,v,false);
		}
	}
	int distance = ga.BFS(1,36);
	cout << "\nSortest Distance will be " << distance << endl;
	return 0;
}

// Sample Output :

// sortest route will be.
// 1 -> 15 -> 29 -> 30 -> 36