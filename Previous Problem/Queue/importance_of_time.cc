#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

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
	queue<int> q;
	int *arr = new int[n]();
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		q.push(data);
	}	
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}
	int time=0;
	int i=0;
	while(!q.empty()){
		int job = q.front();
		if(job==arr[i]){
			time++;
			q.pop();
			i++;
		}else{
			q.pop();
			time++;
			q.push(job);
		}
	}
	cout<<endl<<time;
	return 0;
}

// Sample Input :

// 5
// 5 4 2 3 1
// 5 2 1 4 3

// Sample Output :

// 7