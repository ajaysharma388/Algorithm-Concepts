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
public:
    bool isSorted(vector<int> &nums, int i, int n)
    {
        if(i == n-1)
        {
            return true;
        }
        return nums[i] < nums[i+1] and isSorted(nums, i+1, n); 
    }

    string solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        if(isSorted(arr, 0, n))
        {
            return "Array is Sorted";
        }
        else
        {   
            return "Array is not Sorted";
        }
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

2
6 1 2 3 4 5 6 
6 1 2 3 4 5 3

Sample Output:

TestCase #1 : Array is Sorted
TestCase #2 : Array is not Sorted

*/