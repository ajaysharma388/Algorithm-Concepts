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

vector<string> mappings = {
	"", 
	"", 
	"ABC", 
	"DEF", 
	"GHI", 
	"JKL", 
	"MNO", 
	"PQRS", 
	"TUV", 
	"WXYZ"
};

class Solution {
	vector<string> res;
	string buf;

	void dfs(const string &s, int idx, int n)
	{
		if(idx >= n)
		{
			res.push_back(buf);
			return;
		}
		int num = s[idx]-'0';
		string str = mappings[num];
		for(char ch: str)
		{
			buf.push_back(ch);
			dfs(s, idx+1, n);
			buf.pop_back();
		}
	}
public:
	vector<string> letterCombinations(string digits) 
	{
    	dfs(digits, 0, digits.length());    
    	return res;
    }

    void solve()
    {
    	string input;
    	cin >> input;
    	letterCombinations(input);
    	print();
        return;
    }

    void print()
    {
        cout << "[ ";
        for(string cur: res)
            cout << cur << " ";
        cout << "]\n";
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


Sample Output:


*/
