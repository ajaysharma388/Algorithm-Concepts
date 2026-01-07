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

	void printRecursiveRev(int n)
	{
		if(n == 0) return;
		cout << n << " ";
		printRecursiveRev(n-1);
	}

	void printRecursive(int n)
	{
		if(n == 0) return;
		printRecursive(n-1);
		cout << n << " ";
	}
public:
    void solve()
    {
       int n;
       cin >> n;
       printRecursiveRev(n);
       cout << endl;
       printRecursive(n);
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
        cout << "TestCase #" << t << " : \n";
        s->solve();        
    }
    return 0;
}

/*
Sample Input:

Sample Output:

*/