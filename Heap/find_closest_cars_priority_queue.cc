#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


class Car
{
public:
	int x,y,id;
	Car(const int x,const int y,const int id){
		this->x = x;
		this->y = y;
		this->id = id; 
	}
	int distance(){
		return x*x + y*y;
	}
};

// Definning the functors.
class CarCompare{
public:
	// overridding the round brackets().
	bool operator() (Car a,Car b){
		return a.distance() > b.distance();
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
	int n;
	cin >> n;
	priority_queue<Car,vector<Car>,CarCompare> pq;
	for(int i=0;i<n;++i){
		int xcords,ycords,idNo;
		cin >> xcords >> ycords >> idNo;
		Car c(xcords,ycords,idNo);
		pq.push(c);
	}
	while(!pq.empty()){
		cout<<pq.top().id<<" - ";
		pq.pop();
	}
	return 0;
}