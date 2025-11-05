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
	vector<vector<string>> res;
	vector<string> buf;
	bool isPalindrome(string s, int l, int r)
	{
		while(l < r)
		{
			if(s[l] != s[r]) return false;
			r--;	
			l++;
		}
		return true;
	}
	void dfs(const string &s, int i, int n)
	{
		if(i >= n)
		{
			res.push_back(buf);
			return;
		}
		for(int x = i; x < n; ++x)
		{
			if(isPalindrome(s, i, x))
			{
				buf.push_back(s.substr(i, x-i+1));
				dfs(s, x+1, n);
				buf.pop_back();
			}
		}
	}
	
public:
    vector<vector<string>> partition(string s) 
    {
    	clear();
		dfs(s, 0, s.length());
		return res;
	}  

	void print(vector<string> &list)
    {
        cout << "[ ";
        for(string c: list)
            cout << c << " ";
        cout << "]\n";
    }   

    void solve()
    {
    	string s;
    	cin >> s;
    	cout << s << endl;
    	vector<vector<string>> res = partition(s);
    	for(vector<string> lst: res)
    	{
    		print(lst);
    	}
        return;
    }

    void clear()
    {
    	res.clear();
    	buf.clear();
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

3
CATACA
AAB
ABCBA

Sample Output:

TestCase #1 : 
CATACA
[ C A T A C A ]
[ C A T ACA ]
[ C ATA C A ]
[ CATAC A ]
TestCase #2 : 
AAB
[ A A B ]
[ AA B ]
TestCase #3 : 
ABCBA
[ A B C B A ]
[ A BCB A ]
[ ABCBA ]

*/
