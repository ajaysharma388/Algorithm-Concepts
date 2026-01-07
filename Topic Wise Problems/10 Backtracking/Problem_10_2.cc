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
    void permuteString(string s, int idx, int len, int &cnt)
    {
        if(idx == len)
        {
            cnt++;
            cout << cnt << ": " << s << endl;
            return;
        }
        // take the current characted in the output.
        for(int i = idx; i < len; ++i)
        {
        	swap(s[idx], s[i]);
        	permuteString(s, idx+1, len, cnt);
        	swap(s[idx], s[i]);
        }
        return;
    }
public:
    int solve()
    {
       string s;
       cin >> s;
       int cnt = 0;
       permuteString(s, 0, s.length(), cnt);
       return cnt;
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
        cout << "TestCase #" << t << " : "<< endl;
        int res = s->solve();
        cout << "Number of Subsets are: " << res << endl;        
    }
    return 0;
}

/*
Sample Input:

2
abc
ABCD

Sample Output:

TestCase #1 : 
1: abc
2: acb
3: bac
4: bca
5: cba
6: cab
Number of Subsets are: 6
TestCase #2 : 
1: ABCD
2: ABDC
3: ACBD
4: ACDB
5: ADCB
6: ADBC
7: BACD
8: BADC
9: BCAD
10: BCDA
11: BDCA
12: BDAC
13: CBAD
14: CBDA
15: CABD
16: CADB
17: CDAB
18: CDBA
19: DBCA
20: DBAC
21: DCBA
22: DCAB
23: DACB
24: DABC
Number of Subsets are: 24


*/