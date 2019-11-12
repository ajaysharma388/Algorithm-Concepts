#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void MMAFighter(int *a,int n,int k){
	deque<int> Qi(k);
	int i;
	for(i=0;i<k;++i){
		while(!Qi.empty() && a[i]>=a[Qi.back()]){
			Qi.pop_back();
		}
		Qi.push_back(i);
	}
	for(i=k;i<n;++i){
		cout<<a[Qi.front()]<<" ";
		// 1. removing all the elements which are not in window.
		while(!Qi.empty() && Qi.front()<i-k+1){
			Qi.pop_front();
		}
		// 2. removing elements which are smaller than current.
		while(!Qi.empty() && a[Qi.back()]<=a[i]){
			Qi.pop_back();
		}
		// 3. inserting current element.
		Qi.push_back(i);
	}
	cout<<a[Qi.front()]<<endl;
}

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
	int *a = new int[n];
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	cin >> k;
	MMAFighter(a,n,k);
	return 0;
}