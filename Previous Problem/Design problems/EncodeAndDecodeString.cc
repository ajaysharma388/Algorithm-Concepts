Encode and decode string.

// length(num)#stringItself.

class Solution {
public:
    string encode(vector<string>& strs) 
    {
        string res = "";
        for(auto s: str)
        {
            int cnt = s.length();
            string data = snt.to_str() + "#" + s;
            res += data;
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
    	int cnt = 0;
		int len = s.length();
		int i = 0;
		while(i < len)
		{
			// try to fetch the number.
			while( i != '#')
			{
				// till then we have to form the number.
				cnt *= 10;
				cnt += s[i]-'0';
				i++;
			}  
			// now we are at some index at which we have '#'
			i++;
			string cur = "";
			for(int x = i; x < i+cnt; ++x)
			{
				 cur.push_back(s[x]);
			}
			// push the cur string into result.
			result.push_back(cur);
			i += cnt; 
			cnt = 0;
		}
		return result;    
    }
};