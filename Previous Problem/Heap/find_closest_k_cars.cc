#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


// Class Car reperesents the Id & x,y 
// coordinate of the car in cartesian plane.
class Car
{
public:
	// Member properties.
	int x,y,id;
	// Car Constructor.
	Car(const int x,const int y,const int id){
		this->x = x;
		this->y = y;
		this->id = id; 
	}
	// Get's the distance.
	int distance(){
		return x*x + y*y;
	}
	// prints the Data of Car Object.
	void print(){
		cout<<setprecision(1)<<" Distance : "<<sqrt(this->Car::distance())
		<<" , Id : "<<id<<" | Location : ("<<x<<" , "<<y<<")"<<endl;
	}
};

// Definning the functors.
class CarCompare{
public:
	// overridding the round brackets().
	bool operator() (Car a,Car b){
		// On the basis of it's result we are creating the Min Heap.
		// return a.distance() > b.distance();
		// Uncomment the below and comment the upper line to convert Into Max Heap.
		return a.distance() < b.distance();
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
	int n,k;
	cin >> n;
	priority_queue<Car,vector<Car>,CarCompare> pq;
	for(int i=0;i<n;++i){
		int xcords,ycords;
		cin >> xcords >> ycords;
		Car c(xcords,ycords,i+1);
		pq.push(c);
	}
	cin >> k;
	while(!pq.empty()&&k){
		Car c = pq.top();
		c.print();
		pq.pop();
		k--;
	}
	return 0;
}

// Input : 

// 10
// 5 1 
// 6 -2
// 17 8 
// 18 9 
// 9 10 
// 11 91 
// 0 1 
// 3 2 
// 4 3  
// -1 2
// 4

// Output : Min Heap.

//  Distance : 1 , Id : 7 | Location : (0 , 1)
//  Distance : 2 , Id : 10 | Location : (-1 , 2)
//  Distance : 4 , Id : 8 | Location : (3 , 2)
//  Distance : 5 , Id : 9 | Location : (4 , 3)

// Output : Max Heap.

//  Distance : 9e+01 , Id : 6 | Location : (11 , 91)
//  Distance : 2e+01 , Id : 4 | Location : (18 , 9)
//  Distance : 2e+01 , Id : 3 | Location : (17 , 8)
//  Distance : 1e+01 , Id : 5 | Location : (9 , 10)