/******************************************
* AUTHOR : AJAY SHARMA                    *
* NICK : ajaysharma388                    *
******************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second


void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}

void divide(int &num,int divser) {
	// Base Case.
	if(num < 1) return;
	if(num == 1) return;
	while(num % divser == 0) {
		num /= divser;
	}
	return ;
}

bool isUgly(int num) {
	divide(num,2);
	divide(num,3);
	divide(num,5);
	return (num == 1) ? true : false;
}


int nth_Ugly_number(int n) {
	int count = 1;
	int cur = 1;
	while(count < n) {
		cur++;
		if(isUgly(cur)) count++;
	}
	return cur;
}

// Time Complexity of this Solution : O(N).
// It uses auxilary space : O(N).

int nth_Ugly_number_BU(int n) {
	vector<int> ugly(n+1,0);
	ugly[0] = 1;
	int i2, i3, i5;
	i2 = i3 = i5 = 0;
	unsigned int nextMul2 = 2;
	unsigned int nextMul3 = 3;
	unsigned int nextMul5 = 5;
	unsigned int curUgly = 1;
	for(int i = 1; i < n; ++i) {
		curUgly = min(min(nextMul2,nextMul3), nextMul5);
		ugly[i] = curUgly;
		if(curUgly == nextMul2) {
			i2 += 1;
			nextMul2 = ugly[i2] * 2;
		}
		if(curUgly == nextMul3) {
			i3 += 1;
			nextMul3 = ugly[i3] * 3;
		} 
		if(curUgly == nextMul5) {
			i5 += 1;
			nextMul5 = ugly[i5] * 5;
		}
	}
	return curUgly;
}

int32_t main() {
	fastio(true);
	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		cout << n <<"th ugly number is " << nth_Ugly_number(n) << "." << endl;
		cout << n <<"th ugly number is using BU " << nth_Ugly_number_BU(n) << "." << endl;
	}
	return 0;
}

// Sample Input : 

// 1
// 150

// Sample Output :

// 150th ugly number is 5832.
// 150th ugly number is using BU 5832.