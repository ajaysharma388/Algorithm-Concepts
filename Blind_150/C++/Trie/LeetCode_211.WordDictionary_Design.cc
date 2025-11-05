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

class Trie
{
public:
    vector<Trie*> childs;
    bool isTerminal;
    Trie()
    {
        for(int i = 0; i < 26; ++i)
            this->childs.emplace_back(nullptr);
        this->isTerminal = false;
    }
};

class WordDictionary 
{
    Trie* root;
public:
    WordDictionary() 
    {
        root = new Trie();
    }
    
    void addWord(string word) 
    {
        Trie* cur = root;
        for(char ch: word)
        {
            if(cur->childs[ch-'a'] == nullptr)
            {
                cur->childs[ch-'a'] = new Trie();
            }
            cur = cur->childs[ch-'a'];
        }
        // cout << "Added " << word << endl;
        cur->isTerminal = true;
    }

    bool search_with_index(Trie* head, string word, int idx, int n) 
    {
    	// cout << "starting the serch on"  << word << " from " << idx << endl; 
        Trie* cur = head;
        for(int i = idx; i < n; ++i)
        {
            if(word[i] == '.') return dfs(cur, word, i, n);
            int x = word[i]-'a';
            if(cur->childs[x] == nullptr)
                return false;
            cur = cur->childs[x];
        }
        return true;
    }

    bool dfs(Trie* root, string word, int idx, int n)
    {
        // let's focus on the base case.
        if(idx == n) return root->isTerminal;
        if(word[idx] == '.')
        {
            for(int i = 0; i < 26; ++i)
                if(root->childs[i] != nullptr)
                    return dfs(root->childs[i], word, idx+1, n);
            // if I ever reach this position that mean I do not have any non null childs.
            return false;
        }
        return search_with_index(root, word, idx, n);
    }
    
    bool search(string word) {
        return search_with_index(this->root, word, 0, word.size());
    }

    void solve()
    {
    	int n;
    	cin >> n;
    	while(n--)
    	{
    		int ac;
    		string s;
    		cin >> ac >> s;
    		if(ac == 1)
    		{
    			addWord(s);
    		}
    		else
    		{
    			cout << "Word " << s << ": " << search(s) << endl; 
    		}
    	}
        return;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        WordDictionary *s = new WordDictionary();
        cout << "TestCase #" << t << " : " << endl;
        s->solve();        
    }
    return 0;
}

/*

Sample Input:


Sample Output:


*/
