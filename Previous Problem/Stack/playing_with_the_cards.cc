#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define si stack<int>

bool primes[100005];
vector<int> prime;

void createSieve(){
	primes[2] = true;
	for(int i=3;i<100005;i+=2){
		int j;
		for(j=2;j*j<=i;++j){
			if(i%j==0){
				break;
			}
		}
		if(j*j>i){
			primes[i] = true;
		}
	}
	for(int i=0;i<100005;++i){
		if(primes[i]){
			prime.push_back(i);
		}
	}
	return;
}

void playWithCards(si s,si A,si B,int i,int q){
	if(i>q) return;
	while(!s.empty()){
		if(s.top()%prime[i-1]==0){
			B.push(s.top());
		}else{
			A.push(s.top());
		}
		s.pop();
	}
	while(!B.empty()){
		cout<<B.top()<<endl;
		B.pop();
	}
	si Ar,Br;
	playWithCards(A,Ar,Br,i+1,q);
	if(i==q){
		while(!A.empty()){
			cout<<A.top()<<endl;
			A.pop();
		}
		return;
	}
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(primes,false,sizeof(primes));
	createSieve();
	int n,q;
	cin >> n >> q;
	si s,A,B;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		s.push(data);
	}
	playWithCards(s,A,B,1,q);	
	return 0;
}