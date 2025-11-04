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

int solve1(vector<int> nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> Q;
    for(int num: nums)
    {
        Q.push(num);
        if(Q.size() > k) Q.pop();
    } 
    return Q.top();
}

int solve2(vector<int> nums, int k)
{
    return 0;
}


int main() {
    fastio();
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; ++i)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0); 
        for(int i = 0; i < n; i++) 
        {
            cin >> nums[i];
        }   
        cout << "TestCase #" << i << " :" << solve1(nums, k) << " " << solve2(nums, k) << endl;
    }
    return 0;
}   

/*
Sample Testcase:

2
5 2
2 3 1 5 4
7 3
2 3 1 1 5 5 4

Sample Output:

TestCase #1 :4
TestCase #2 :5
*/