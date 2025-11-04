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
	vector<vector<int>> subsetsList;
public:
	void dfs(vector<int> &nums, vector<int> &buf, int idx, int n)
	{
		if(idx == n)
		{
			subsetsList.push_back(buf);
			return;
		}
		// do not add this number
		dfs(nums, buf, idx+1, n);
		// add the number
		buf.emplace_back(nums[idx]);
		dfs(nums, buf, idx+1, n);
		buf.pop_back();
		return;
	}

	vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> buf;
        dfs(nums, buf, 0, nums.size());
        return subsetsList;
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
    	for(int i = 0; i < n; ++i)
    		cin >> nums[i];
    	vector<vector<int>> subsetList = subsets(nums);
    	for(vector<int> subset: subsetList)
    		print(subset);

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
1 7
3 1 2 3
4 1 2 3 4

Sample Output:

TestCase #1 :
[ ]
[ 7 ]
TestCase #2 :
[ ]
[ 3 ]
[ 2 ]
[ 2 3 ]
[ 1 ]
[ 1 3 ]
[ 1 2 ]
[ 1 2 3 ]
TestCase #3 :
[ ]
[ 4 ]
[ 3 ]
[ 3 4 ]
[ 2 ]
[ 2 4 ]
[ 2 3 ]
[ 2 3 4 ]
[ 1 ]
[ 1 4 ]
[ 1 3 ]
[ 1 3 4 ]
[ 1 2 ]
[ 1 2 4 ]
[ 1 2 3 ]
[ 1 2 3 4 ]


*/
