#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
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

class Solution 
{
public:
	int power(int m, int n)
	{
		if(n == 0) return 1;
		return m*power(m, n-1);
	}

	int powerFast(int m, int n)
	{
		if(n == 0) return 1;
		int half = powerFast(m, n/2);
		int res = half*half;
		if(n & 1)
		{
			return m*res;
		}
		return res;
	}

    void solve()
    {
       int m, n;
       cin >> m >> n;
       cout << power(m, n) << " " << powerFast(m, n) << endl;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << t << " : ";
        s->solve();        
    }
    return 0;
}

/*
Sample Input:

2
2 6 
3 7

Sample Output:

TestCase #1 : 64 64
TestCase #2 : 2187 2187

*/