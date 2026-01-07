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
    void printRecursiveDec(int n)
    {
    	if( n == 0 ) return;
    	cout << n << " ";
    	printRecursiveDec(n-1);
    }

    void printRecursiveInc(int n)
    {
    	if( n == 0 ) return;
    	printRecursiveInc(n-1);
    	cout << n << " ";
    }

    void solve()
    {
        int n;
        cin >> n;
        cout << "\nDecreasing : ";
        printRecursiveDec(n);
        cout << "\nIncreasing : ";
        printRecursiveInc(n);
        cout << endl;
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
6 
7

Sample Output:

TestCase #1 : 
Decreasing : 6 5 4 3 2 1 
Increasing : 1 2 3 4 5 6 
TestCase #2 : 
Decreasing : 7 6 5 4 3 2 1 
Increasing : 1 2 3 4 5 6 7 
*/