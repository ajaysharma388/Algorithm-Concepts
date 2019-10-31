#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Queue
{
public:
	int *queue
	Queue(const int size){
		queue = new int[size];
	}
	~Queue(){
		delete []queue;
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
	
	return 0;
}