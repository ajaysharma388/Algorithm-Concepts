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
	vector<int> res;
	vector<int> dr;
	vector<int> dc;
	int idx;
public:

	void init()
	{
		this->res = {};
		this->dr = {0, 1, 0, -1};
		this->dc = {1, 0, -1, 0};
		this->idx = 0;
	}

	void spiralPrint(int row, int col, vector<vector<int>> &mat)
	{
		vector<vector<bool>> vis(row, vector<bool>(col, false));
		init();
		int r = 0, c = 0;
		for(int i = 0; i < row*col; ++i)
		{
			this->res.push_back(mat[r][c]);
			vis[r][c] = true;
			int _r = dr[idx] + r;
			int _c = dc[idx] + c;

			// now we have to check if there are in bound
			if(_r >= 0 and _r < row and _c >= 0 and _c < col and !vis[_r][_c])
			{
				r = _r;
				c = _c;
			}
			else
			{
				idx = (idx+1)%4;
				r += dr[idx];
				c += dc[idx];
			}
		}
	}

    vector<int> solve()
    {
    	int m, n;
    	cin >> m >> n;
    	vector<vector<int>> mat(m, vector<int>(n, 0));
    	for(int i = 0; i < m; ++i)
    		for(int j = 0; j < n; ++j)
    			cin >> mat[i][j];

   		spiralPrint(m, n, mat);
   		return this->res;
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
        cout << "TestCase #" << t << " : ";
        vector<int> res = s->solve();
        for(int num: res)
        {
        	cout << num << " ";
        }         
        cout << endl;
    }
    return 0;
}

/*

Sample Input:
1
5 6
1 2 3 4 5 6
18 19 20 21 22 7
17 28 29 30 23 8
16 27 26 25 24 9
15 14 13 12 11 10

Sample Output:
TestCase #1 : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 

*/
