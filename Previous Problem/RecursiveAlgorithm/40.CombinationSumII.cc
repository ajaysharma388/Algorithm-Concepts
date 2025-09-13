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
        if(target == 0)
        {
            res.push_back(buf);
            return;
        }
        if(idx >= n or target < 0) return;
        // include the current character.
        buf.push_back(nums[idx]);
        dfs(nums, buf, idx+1, n, target-nums[idx]);
        buf.pop_back();
        // exclude the current character.
        while(idx+1 < n and nums[idx] == nums[idx+1])
        {
            idx++;
        }
        dfs(nums, buf, idx+1, n, target);
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

3
8 8
9 2 2 4 6 1 5 1
5 7
1 2 3 4 5
6 11
3 2 5 1 4 10

Sample Output:

TestCase #1 :
[ 1 1 2 4 ]
[ 1 1 6 ]
[ 1 2 5 ]
[ 2 2 4 ]
[ 2 6 ]
TestCase #2 :
[ 1 2 4 ]
[ 2 5 ]
[ 3 4 ]
TestCase #3 :
[ 1 2 3 5 ]
[ 1 10 ]
[ 2 4 5 ]

*/
