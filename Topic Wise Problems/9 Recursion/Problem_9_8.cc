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
	int numberOfWaysToGo(int n)
	{
		if(n == 0 or n == 1) return 1;
		return numberOfWaysToGo(n-1) + (n-1)*numberOfWaysToGo(n-2);
	}

    int solve()
    {
    	int n;
    	cin >> n;
    	return numberOfWaysToGo(n);
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
1
2
3
4

Sample Output:

TestCase #1 : 1
TestCase #2 : 2
TestCase #3 : 4
TestCase #4 : 10
*/