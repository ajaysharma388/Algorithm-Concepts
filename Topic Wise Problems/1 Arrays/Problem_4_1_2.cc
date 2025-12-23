#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    if(read) {
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

vector<pair<int, int>> solve(vector<int> nums, int target)
{
    vector<pair<int, int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, right = n - 1;
    bool found = false;     
    while(left <= right) 
    {
        int sum = nums[left] + nums[right];
        if(sum == target)
        {
            res.push_back({nums[left], nums[right]});
            left++;
        }
        else if(sum < target)
        {
            left++;
        }
        else 
        {
            right--;
        }           
    }
    return res;
}

int main() {
    fastio();
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; ++i)
    {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n, 0); 
        for(int i = 0; i < n; i++) 
        {
            cin >> nums[i];
        }   
        vector<pair<int, int>> res = solve(nums, x);
        cout << "TestCase #" << i << " : ";
        if(res.size() > 0) 
        {
            for(auto data: res)
            {
                cout << "[" << data.first << ", " << data.second << "], ";
            }
            cout << endl;
        }
        else
        {
            cout << "No such pair found" << endl;
        }
    }
    return 0;
}   


/*
Sample Testcase:

2
10 17
8 7 6 1 25 -8 11 5 9 12
6 10
8 -3 2 13 6 4

Sample Output:

TestCase #1 : [-8, 25], [5, 12], [6, 11], [8, 9], 
TestCase #2 : [-3, 13], [2, 8], [4, 6], 
*/