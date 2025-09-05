#include<bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Solution {
    string buildMappings(string s)
    {
        vector<int> cnt(26, 0);
        for(char ch: s)
            cnt[ch-'a']++;
        
        string out = "";
        for(int i = 0; i < 26; ++i)
            if(cnt[i])
            {
                string cur = (char)(i+'a')+to_string(cnt[i]);
                out.append(cur);
            }
        
        return out;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        
        for(string s: strs)
            mp[buildMappings(s)].emplace_back(s);
        
        for(auto data: mp)
            res.emplace_back(data.second);
        
        return res;
    }
};

int main()
{
    fastio();
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<string> strs(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> strs[i];
            // cout << strs[i] << " : " << buildMappings(strs[i]) << endl;
        }
        Solution *sol = new Solution();
        vector<vector<string>> anagrams = sol->groupAnagrams(strs);
        for(vector<string> list: anagrams)
        {
            for(string s: list)
            {
                cout << s << ",";
            }
            cout << endl;
        } 
    }
    return 0;
}