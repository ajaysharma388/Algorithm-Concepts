#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

map<string,int> mp;
vector<string> vec;
void sumItup(int *arr,int *res,int n,int k,int current,int i,int j){
	if(i==n and current==k){
		string s = "";
		int sum = 0;
		for(int c=0;c<j;++c){
			sum+=res[c];
			string t = to_string(res[c]);
			s+=t;
			s+=" ";
		}
		if(mp.find(s)==mp.end()){
			vec.push_back(s);
			mp[s]=true;
		}
		return ;
	}
	if(i==n) return;

	sumItup(arr,res,n,k,current,i+1,j);
	res[j] = arr[i];
	sumItup(arr,res,n,k,current+res[j],i+1,j+1);
	return;
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
	int *arr = new int[n]();
	int *res = new int[n]();
	bool issorted = true;
	cin >> arr[0];
	for(int i=1;i<n;++i){
		cin >> arr[i];
		if(arr[i-1]>arr[i]) issorted = false;
		res[i] = false;
	}
	cin>>k;
	if(!issorted){
		sort(arr,arr+n);
	}
	sumItup(arr,res,n,k,0,0,0);
	for(int i=vec.size()-1;i>=0;--i){
		cout<<vec[i]<<endl;
	}
    delete []arr;
    delete []res;
	return 0;
}

// Sample Input :

// 15
// 57 79 16 3 83 70 78 14 5 8 36 51 47 93 72 
// 86

// 7
// 10 1 2 7 6 1 5
// 8

// Sample Output :

// 3 5 8 70 
// 3 5 78 
// 3 36 47 
// 3 83 
// 5 8 16 57 
// 5 14 16 51 
// 8 78 
// 14 72 
// 16 70 

// 1 1 6 
// 1 2 5 
// 1 7 
// 2 6 