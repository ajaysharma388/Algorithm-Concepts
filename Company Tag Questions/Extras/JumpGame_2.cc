#include<bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Solution {
public:    
    int help(vector<int> &nums, int i, int j) 
    {
        // base cases.
        if(i == j)
        {
            return 0;
        }
        if(i > j) 
        {
            return INT_MAX;
        }
        int cur = INT_MAX;
        // recursive case.
        for(int x = 1; x<= nums[i]; ++x) {
            cur = min(cur, help(nums, i+x, j));
        }
        return cur == INT_MAX ? cur : cur+1;
    }
    
    int jumpIterative(vector<int>& nums) {
        int n = nums.size();
        // Dp Array.
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n-1; ++i)
            for(int x = 1; x<= nums[i]; ++x)
                if(i + x <= n-1) 
                    dp[i + x] = min(dp[i + x], dp[i] + 1);
        return dp[n-1];
    }

    int jumpRecursive(vector<int>& nums) {
        int n = nums.size();
        return help(nums, 0, n-1);
    }
};

int main() 
{
    fastio();
    int testCase;
    cin >> testCase;
    while( testCase-- )
    {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> nums[i];
        Solution *game = new Solution();
        cout << "JumpIterative :" << game->jumpIterative(nums) << endl;
        cout << "JumpRecursive :" << game->jumpRecursive(nums) << endl;
    }
    return 0;
}