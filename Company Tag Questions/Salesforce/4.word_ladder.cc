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
public:
    string getSustr(string s, int i, int j)
    {
        if(j == 0) return "";
        return s.substr(i, j);
    }
    
    bool isPresent(vector<string> &wordList, string word)
    {
        for(string s: wordList)
            if(s == word) return true;
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if(!isPresent(wordList, endWord)) return 0;
        if(!isPresent(wordList, beginWord)) wordList.push_back(beginWord);
        unordered_map<string, vector<string>> mp;
        for(string word: wordList)
        {
            for(int i = 0; i < word.size(); ++i)
            {
                string pat = getSustr(word, 0, i) + "*" + word.substr(i+1);
                // cout << word << " " << pat << endl;
                mp[pat].push_back(word);
            }
        }
        bool canSearch = false;
        for(auto p: mp)
            if(p.second.size() > 1)
            {    
                canSearch = true;
                break;
            }
        int res = 0;
        if(canSearch)
        {
            queue<string> Q;
            set<string> vis;
            res += 1;
            vis.insert(beginWord);
            Q.push(beginWord);
            while (!Q.empty())
            {
                for(int i = 0; i < Q.size(); ++i)
                {
                    string word = Q.front();
                    Q.pop();
                    if(word == endWord) return res;
                    for(int j = 0; j < word.size(); ++j)
                    {
                        string pat = getSustr(word, 0, j) + "*" + word.substr(j+1);
                        for(string nbr: mp[pat])
                        {
                            if(vis.find(nbr) == vis.end())
                            {
                                vis.insert(nbr);
                                Q.push(nbr);
                            }
                        }
                    }
                }
                res += 1;
            }
        }
        return res;
    }

    void solve()
    {
    	int n;
    	cin >> n;
    	vector<string> wordList(n);
    	string beginWord, endWord;
    	cin >> beginWord >> endWord;
    	for (int i = 0; i < n; ++i)
    		cin >> wordList[i];
    	return ladderLength(beginWord, endWord, wordList);
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
        cout << "TestCase #" << t << " : " << s->solve() << endl;        
    }
    return 0;
}

/*

Sample Input:


Sample Output:


*/
