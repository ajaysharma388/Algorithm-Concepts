class Solution {
public:
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


    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        
        for(string s: strs)
            mp[buildMappings(s)].emplace_back(s);
        
        for(auto data: mp)
        {
            cout << data.first << endl;
            res.emplace_back(data.second);
        }
        return res;
    }
};