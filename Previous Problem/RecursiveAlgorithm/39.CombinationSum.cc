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

class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int> &nums, 
                vector<int> &buf,
                int idx,
                int n, 
                int target)
    {
        if(idx >= n) return;
        if(target == 0)
        {
            res.push_back(buf);
            return;
        }
        for(int i = idx; i < n; ++i)
        {
            if(target-nums[i] < 0) return;
            buf.push_back(nums[i]);
            dfs(nums, buf, i, n, target-nums[i]);
            buf.pop_back();
        }
        return;
    }

    void combinationSum(vector<int>& nums, int target) 
    {
        vector<int> buf;
        sort(nums.begin(), nums.end());
        dfs(nums, buf, 0, nums.size(), target);
        return;
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
        int n, target;
        cin >> n >> target;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i) cin >> nums[i];
        combinationSum(nums, target);
        for(vector<int> subset: res)
        {
            print(subset);
        }
        return;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int testCase = 1; testCase <= tc; ++testCase)
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << testCase << " :\n";
        s->solve();        
    }
    return 0;
}

/*

Sample Input:

1
6 11
3 2 5 1 4 10

Sample Output:

TestCase #1 :
[ 1 1 1 1 1 1 1 1 1 1 1 ]
[ 1 1 1 1 1 1 1 1 1 2 ]
[ 1 1 1 1 1 1 1 1 3 ]
[ 1 1 1 1 1 1 1 2 2 ]
[ 1 1 1 1 1 1 1 4 ]
[ 1 1 1 1 1 1 2 3 ]
[ 1 1 1 1 1 1 5 ]
[ 1 1 1 1 1 2 2 2 ]
[ 1 1 1 1 1 2 4 ]
[ 1 1 1 1 1 3 3 ]
[ 1 1 1 1 2 2 3 ]
[ 1 1 1 1 2 5 ]
[ 1 1 1 1 3 4 ]
[ 1 1 1 2 2 2 2 ]
[ 1 1 1 2 2 4 ]
[ 1 1 1 2 3 3 ]
[ 1 1 1 3 5 ]
[ 1 1 1 4 4 ]
[ 1 1 2 2 2 3 ]
[ 1 1 2 2 5 ]
[ 1 1 2 3 4 ]
[ 1 1 3 3 3 ]
[ 1 1 4 5 ]
[ 1 2 2 2 2 2 ]
[ 1 2 2 2 4 ]
[ 1 2 2 3 3 ]
[ 1 2 3 5 ]
[ 1 2 4 4 ]
[ 1 3 3 4 ]
[ 1 5 5 ]
[ 1 10 ]
[ 2 2 2 2 3 ]
[ 2 2 2 5 ]
[ 2 2 3 4 ]
[ 2 3 3 3 ]
[ 2 4 5 ]
[ 3 3 5 ]
[ 3 4 4 ]

*/

