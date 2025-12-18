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
public:
    // this solution is correct but the problem with this is it's O(n^n)
	int dfs(int i, int step, vector<int> &nums, vector<int> &dp, int n)
	{
		if( i >= n )
			return INT_MAX;
		
		if(dp[i] != INT_MAX and step > dp[i]) 
            return dp[i];

		if(i == n-1)
		{
			dp[i] = min(dp[i], step);
			return dp[i];
		}
		// try to move to all posible pocitions.
		for(int x = nums[i]; x > 0; --x)
			dp[i] = min(dp[i], dfs(i + x, step+1, nums, dp, n));
		return dp[i];
	}

	int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // initialise the dp array.
		for (int i = 0; i < n; ++i)
			dp[i] = INT_MAX;
		int ans = dfs(0, 0, nums, dp, n);		
		return ans == INT_MAX ? -1 : ans;
    }

    int jump_efficient(vector<int> &nums)
    {
    	int n = nums.size();
    	int res = 0, end = 0, far = 0;
    	for(int i = 0; i < n-1; ++i)
    	{
    		far = max(far, i+nums[i]);
    		if( i == end )
    		{
    			res += 1;
    			end = far;
    		}
    	}
    	return res;
    }

    int solve()
    {
    	int n;
    	cin >> n;
    	vector<int> nums(n, 0);
    	for (int i = 0; i < n; ++i)
    		cin >> nums[i];
        return jump(nums);
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


Sample Output:


*/
