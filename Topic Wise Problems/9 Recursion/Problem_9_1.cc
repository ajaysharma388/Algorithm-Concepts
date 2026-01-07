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
    int factorial(int num)
    {
        if ( num == 0 ) return 1;
        return num*factorial(num-1); 
    }

    int solve()
    {
       int n;
       cin >> n;
       return factorial(n);
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
8
5
9
7

Sample Output:
TestCase #1 : 40320
TestCase #2 : 120
TestCase #3 : 362880
TestCase #4 : 5040

*/