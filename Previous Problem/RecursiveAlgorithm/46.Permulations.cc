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
    vii dfs(vector<int> &nums, 
                int idx,
                int n)
    {
        if(idx == n) return {{}};
        // try forming the permutations for the 
        // rest of the elements other than num at idx
        vii res = dfs(nums, idx+1, n);
        // now for the new list after appending the 
        // items at all posible positions.
        vii current_permutations = {};
        for(vector<int> subset: res)
        {
            int len = subset.size();
            for(int i = 0; i <= len; ++i)
            {
                vector<int> cur;
                int x = 0;
                bool added = false;
                while(true)
                {
                    if(x == i && !added)
                    {
                        added = true;
                        cur.push_back(nums[idx]);
                        continue;
                    }
                    if(x < len) cur.push_back(subset[x++]);  
                    else break;
                }
                current_permutations.emplace_back(cur);
            }
        }
        return current_permutations;
    }


    vii permute(vector<int>& nums) 
    {    
        return dfs(nums, 0, nums.size());
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
        vi nums(n, 0);
        for(int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        vii res = permute(nums);
        for(vi lst: res)
        {
            print(lst);
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
3 1 2 3
4 1 2 3 4
2 3 4

Sample Output:

TestCase #1 :
[ 1 2 3 ]
[ 2 1 3 ]
[ 2 3 1 ]
[ 1 3 2 ]
[ 3 1 2 ]
[ 3 2 1 ]
TestCase #2 :
[ 1 2 3 4 ]
[ 2 1 3 4 ]
[ 2 3 1 4 ]
[ 2 3 4 1 ]
[ 1 3 2 4 ]
[ 3 1 2 4 ]
[ 3 2 1 4 ]
[ 3 2 4 1 ]
[ 1 3 4 2 ]
[ 3 1 4 2 ]
[ 3 4 1 2 ]
[ 3 4 2 1 ]
[ 1 2 4 3 ]
[ 2 1 4 3 ]
[ 2 4 1 3 ]
[ 2 4 3 1 ]
[ 1 4 2 3 ]
[ 4 1 2 3 ]
[ 4 2 1 3 ]
[ 4 2 3 1 ]
[ 1 4 3 2 ]
[ 4 1 3 2 ]
[ 4 3 1 2 ]
[ 4 3 2 1 ]
TestCase #3 :
[ 3 4 ]
[ 4 3 ]

*/
