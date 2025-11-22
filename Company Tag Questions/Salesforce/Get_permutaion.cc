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
	void print(vector<int> &buf)
	{
		cout << "[";
		for(int num: buf)
		{
			cout << num << "";
		}
		cout << "], ";
	}

    void dfs(vector<int> &buf, vector<vector<int>> &res, int i, int n)
	{
		if(i == n)
		{
			res.push_back(buf);
			return;
		}
		// now make the recursive call
		for(int x = i; x < n; ++x)
		{
			swap(buf[i], buf[x]);
			dfs(buf, res, i+1, n);
			swap(buf[i], buf[x]);
		}
		return;
	}
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, res, 0, nums.size());
        return res;
    }

    void solve()
    {
    	int n;
    	cin >> n;
    	vector<int> buf(n);
    	for(int i = 0; i < n; ++i)
    		cin >> buf[i];
    	vector<vector<int>> res = permute(buf);
    	for( vector<int> lst: res )
    		print(lst);
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
        cout << "TestCase #" << t << " : " << endl;
       	s->solve();        
    }
    return 0;
}

/*

Sample Input:
1
3 1 2 3

Sample Output:
TestCase #1 : 
[123], [132], [213], [231], [321], [312], 

*/
