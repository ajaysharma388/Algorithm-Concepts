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

class URLShortnerService {
    bool isEnded;
    unordered_map<string, int> storeInfo;
    unordered_map<int, string> storeData;
    
    char addKey(string key)
    {
        int pos = 0;
        if(storeInfo.find(key) != storeInfo.end())
            pos = storeInfo[key];
        else
        {
            pos = storeInfo.size();
            storeInfo[key] = pos;
            storeData[pos] = key;
        }
        return (char)('a'+pos);
    }

    string getKey(char key)
    {
        int pos = (int)(key-'a');
        return storeData[pos];
    }

public:
    URLShortnerService()
    {
        storeData.clear();
        storeInfo.clear();
        isEnded = false;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {   
        regex re("[//,/]");
        sregex_token_iterator it(longUrl.begin(), longUrl.end(), re, -1);
        sregex_token_iterator end;
        string shortUrl = "";
        while(it != end)
        {
            string cur = *it;
            if(cur.length()) shortUrl.push_back(addKey(cur));
            ++it;
        }
        isEnded = longUrl[longUrl.length()-1] == '/';
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        string longUrl = "";
        string data = "//";
        int len = shortUrl.length();
        for(int i = 0; i < len; ++i)
        {
            char ch = shortUrl[i];
            if(longUrl.length() != 0)
                data = "/";
            longUrl.append(getKey(ch));
            if(i != len - 1) longUrl.append(data);
        }
        if(isEnded) longUrl.append(data);
        return longUrl;
    }
};


int main() {
    fastio();
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; ++i)
    {
        URLShortnerService *url = new URLShortnerService();
        string inputUrl;
        cin >> inputUrl;
        string shortUrl = url->encode(inputUrl);
        string longUrl = url->decode(shortUrl);
        cout << "TestCase #" << i << " : " << shortUrl << endl;
        cout << "TestCase #" << i << " : " << longUrl << endl;
    }
    return 0;
}   

/*
Sample Testcase:

2
https://www.linkedin.com/in/ajaysharma388/
https://github.com/ajaysharma388/Algorithm-Concepts

Sample Output:

TestCase #1 :4
TestCase #2 :5
*/