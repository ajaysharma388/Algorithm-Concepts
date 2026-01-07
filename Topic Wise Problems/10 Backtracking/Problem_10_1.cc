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
    void getSubSets(string s, string buf, int &cnt, int idx)
    {
        if(s.length() == idx)
        {
            cnt++;
            cout << cnt << ": " << buf << endl;
            return;
        }
        // take the current characted in the output.
        buf.push_back(s[idx]);
        getSubSets(s, buf, cnt, idx+1);
        buf.pop_back();
        getSubSets(s, buf, cnt, idx+1);
        return;
    }
public:
    int solve()
    {
       string s;
       cin >> s;
       int cnt = 0;
       getSubSets(s, "", cnt, 0);
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
2: ab
3: ac
4: a
5: bc
6: b
7: c
8: 
Number of Subsets are: 8
TestCase #2 : 
1: ABCD
2: ABC
3: ABD
4: AB
5: ACD
6: AC
7: AD
8: A
9: BCD
10: BC
11: BD
12: B
13: CD
14: C
15: D
16: 
Number of Subsets are: 16

*/