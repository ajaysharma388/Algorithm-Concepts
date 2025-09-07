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

vector<vector<int>> getPascalTriangle(int num)
{
    vector<vector<int>> res = {};
    for(int i = 0; i < num; ++i)
    {
        vector<int> cur = {1};
        if(i > 0)
        {
            for(int j = 1; j < res[i-1].size(); ++j)
            {
                cur.emplace_back(res[i-1][j-1] + res[i-1][j]);
            }
            cur.emplace_back(1);
        }
        res.push_back(cur);
    }
    return res;
}


int main()
{
    fastio();
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        auto res = getPascalTriangle(n);
        cout << "Pascal Triangle of size " << n << endl;
        for(auto curRow: res)
        {
            for(int num: curRow)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

/*
Sample Input:

3
5
7
4

Sample Output:

Pascal Triangle of size 5
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
Pascal Triangle of size 7
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
Pascal Triangle of size 4
1 
1 1 
1 2 1 
1 3 3 1 

*/