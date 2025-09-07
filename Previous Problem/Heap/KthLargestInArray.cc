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
    int find(vector<int> &nums, int s, int e)
    {
        double r = rand()*3.14+3.14;
        int pivot = (long long)(r)%(e-s+1) + s;
        swap(nums[pivot], nums[e]);
        pivot = e;
        int i = s-1, j = s;
        for(; j < e; ++j)
        {
            if(nums[j] <= nums[pivot])
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[pivot], nums[i+1]);
        return i+1;
    }

    int find_1(vector<int> &nums, int s, int e, int k)
    {
        int pivot = e;
        int i = s-1, j = s;
        for(; j < e; ++j)
        {
            if(nums[j] <= nums[pivot])
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[pivot], nums[i+1]);
        if(i+1 > k) return find_1(nums, s, i, k);
        else if(i+1 < k) return find_1(nums, i+1, e, k);
        else return nums[i+1];
    }

public:

    int findKthLargest(vector<int>& nums, int k) 
    {
        fastio();
        int n = nums.size();
        int s = 0, e = n-1;
        int expectedIdx = 0;
        while(true) 
        {
            int idx = find(nums, s, e);
            expectedIdx = n-k;
            if(idx == expectedIdx)
                break;
            if(idx < expectedIdx)
                s = idx+1;
            else
                e = idx-1;
        }
        return nums[expectedIdx];
    }

    int findKthLargest_1(vector<int>& nums, int k) 
    {
        fastio();
        int n = nums.size();
        return find_1(nums, 0, n-1, n-k);
    }

    void solve()
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> nums[i];
        cout << findKthLargest_1(nums, k) << endl;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; ++i) 
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << i << " : ";
        s->solve();        
    }
    return 0;
}

/*

Sample Input:

4
8 3
7 2 3 1 1 5 5 4
16 7
77 22 31 1 11 5 55 34 71 27 33 19 21 15 25 4 
5 2
2 3 1 5 4
16 4
77 22 31 1 11 5 55 34 71 27 33 19 21 15 25 4
15 7
3 2 1 5 6 4 3 2 3 1 2 4 5 5 6 

Sample Output:

TestCase #1 : 5
TestCase #2 : 27
TestCase #3 : 4
TestCase #4 : 34

*/