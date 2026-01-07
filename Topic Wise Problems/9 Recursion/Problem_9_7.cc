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

	int getPossibleBinaryStrings(int n)
	{
		if(n <= 0)
		{
			return 1;
		}
		// if we put the 0 at the current position.
		int zero = getPossibleBinaryStrings(n-1); 
		// if we put the 1 at the current position that means we cannot place another one at next pos.
		int one = getPossibleBinaryStrings(n-2); 
		return one+zero;
	}

    int solve()
    {
    	int n;
    	cin >> n;
      	return getPossibleBinaryStrings(n);
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
        cout << "TestCase #" << t << " : " << s->solve() << endl;        
    }
    return 0;
}

/*
Sample Input:

4
2
5
6 
7

Sample Output:

TestCase #1 : 3
TestCase #2 : 13
TestCase #3 : 21
TestCase #4 : 34
*/