
class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        set<vector<int>> ans;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
        {
            int cur = -1*arr[i];
            if(mp.find(cur) != mp.end())
                ans.insert({min(arr[i],cur), max(arr[i],cur)});
            mp[arr[i]] = i;
        }
        return vector(ans.begin(), ans.end());
    }
};