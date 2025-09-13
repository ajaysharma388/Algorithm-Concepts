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

#define vii vector<vector<int>>
#define vi vector<int>

class Solution 
{
public:
    vii subsetsWithDup(vector<int>& nums) 
    {
        set<vi> res;
        int n = (1 << nums.size())-1;
        for(int i = 0; i <= n; ++i)
        {
            vi cur = {};
            for(int j = 0; j <= nums.size(); ++j)
                if(i & (1 << j)) cur.emplace_back(nums[j]);
            sort(cur.begin(), cur.end());
            res.insert(cur);
        }
        return vector(res.begin(), res.end());
    }

    void print(vector<int> &list)
    {
        cout << "[ ";
        for(int num: list)
            cout << num << " ";
        cout << "]\n";
    }

    void solve()
    {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i) cin >> nums[i];
        vii res = subsetsWithDup(nums);
        for(vi lst: res) print(lst);
        return;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for (int testCase = 1; testCase <= tc; ++testCase)
    {    
        Solution *s = new Solution();       
        cout << "TestCase #" << testCase << " :\n";
        s->solve();         
    }
    return 0;
}

/*

Sample Input:

3
3 1 2 3
4 1 2 3 4
2 3 4

Sample Output:

TestCase #1 :
[ ]
[ 1 ]
[ 1 2 ]
[ 1 2 3 ]
[ 1 3 ]
[ 2 ]
[ 2 3 ]
[ 3 ]
TestCase #2 :
[ ]
[ 1 ]
[ 1 2 ]
[ 1 2 3 ]
[ 1 2 3 4 ]
[ 1 2 4 ]
[ 1 3 ]
[ 1 3 4 ]
[ 1 4 ]
[ 2 ]
[ 2 3 ]
[ 2 3 4 ]
[ 2 4 ]
[ 3 ]
[ 3 4 ]
[ 4 ]
TestCase #3 :
[ ]
[ 3 ]
[ 3 4 ]
[ 4 ]


*/
