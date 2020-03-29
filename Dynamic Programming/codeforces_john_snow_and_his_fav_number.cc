#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x,k;
	cin >> n >> k >> x;
	int *freq = new int[1500]();
	int *temp = new int[1500]();
	// taking the input.
	for(int i = 0; i < n; ++i) { 
		int p;
		cin >> p;
		freq[p]++;
	}
	while(k--) {
		// copy the content.
		for(int i = 0; i < 1500; ++i) {
			temp[i] = freq[i];
		}
		/*
			write your logic here.
		*/
		int parity = 1;
		for(int i = 0; i < 1500; ++i) {
			if(freq[i]) {
				int cur = (i^x);
				int changed_value = freq[i]/2;
				if(parity) {
					changed_value += (freq[i] & 1);
				}
				temp[i] -= changed_value;
				temp[cur] += changed_value;
				parity ^= (freq[i] & 1);
			}
		}
		// copy the content.
		for(int i = 0; i < 1500; ++i) {
			freq[i] = temp[i];
		}
	}
	delete []temp;
	int max_val = INT_MIN;
	int min_val = INT_MAX;
	for(int i = 0; i < 1500; ++i) {
		if(freq[i]) {
			max_val = max(max_val,i);
			min_val = min(min_val,i); 
		}
	}
	cout << max_val << " " << min_val << endl;
	delete []freq;
	return 0;
}

// Sample Input :

// 5 1 2
// 9 7 11 15 5

// 2 100000 569
// 605 986

// Sample Output :

// 13 7
// 986 605