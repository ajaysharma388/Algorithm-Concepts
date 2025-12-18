#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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


ll shift(string &s, int n, bool isStart)
{
    if(!isStart)
    {
		string temp;
		temp = s.substr(1, n-1);
		temp.push_back(s[0]);
		s = temp;
    }
    ll pow = 1;
    ll res = 0;
    for(int i = n-1; i >= 0; --i)
    {
        res += pow*(s[i]-'0');
        pow = pow << 1;
    }
    return res;
}

ll find(string s, int n, int k)
{
    ll start = shift(s, n, true);
    ll end = INT_MIN;
    ll cnt = 0;
    ll p = -1;
    ll temp = 0;
    for(int i = 1; i <= n; ++i)
    {
		temp = shift(s, n, false);
        if(end < temp)
		{
			end = temp;
			cnt = i;
	   	} else if(temp == start)
		{
			p = i-cnt;
			break;
    	}
   	}
	if(p == -1)
		return (cnt+(k-1)*n);
	else 
		return (cnt+(k-1)*p);
}

int solve()
{
	//read the matrix.
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll cnt = find(s, n, k);
	ll result = cnt + (k-1)*(cnt-1);
	return result;
}


int main() {
	fastio(true);
	int num;
	cin >> num;    //Reading input from STDIN
	for(int i = 1; i <= num; ++i)
	{
		// now we have to do some work for each test case.
		cout << "TestCase #"<< i << ": " << solve() << endl;
	}
	return 0;
}

// Sample Input Test Cases

// 2
// 5 2
// 10101
// 6 2
// 010101

// Sample Output for Test Cases

// TestCase #1: 9
// TestCase #2: 3