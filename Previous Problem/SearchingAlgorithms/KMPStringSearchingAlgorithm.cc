#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * Do pattern matching using KMP algorithm
 * 
 * Runtime complexity - O(m + n) where m is length of text and n is length of pattern
 * Space complexity - O(n)
 */

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

bool hasSubstring(string text, string pattern)
{
    int i=0;
    int j=0;
    int k = 0;
    while(i < text.length() && j < pattern.length())
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j=0;
            k++;
            i = k;
        }
    }
    if(j == pattern.length())
    {
        return true;
    }
    return false;
}

vector<int> computeTemporaryArray(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for(int i=1; i < pattern.length();)
    {
        if(pattern[i] == pattern[index]){
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if(index != 0)
            {
                index = lps[index-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


vector<int> computeTemporaryArrayA(string pattern)
{
    int n = pattern.length(), idx = 0;
    vector<int> data(n, 0);
    for(int i = 1; i < n;)
    {
        if(pattern[idx] == pattern[i])
        {
            data[i] = idx+1;
            idx++;
            i++;
        }
        else
        {
            if(idx == 0)
            {
                data[i] = 0;
                i++;
            } 
            else
            {
                idx = data[idx-1];
            }
        }
    }
    return data;
}


/**
 * KMP algorithm of pattern matching.
 */
bool KMP(string text, string pattern)
{    
    vector<int> lps = computeTemporaryArray(pattern);
    int i=0;
    int j=0;
    while(i < text.length() && j < pattern.length())
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(j == pattern.length()){
        return true;
    }
    return false;
}

int main() 
{
    fastio(true);
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string text = "abcxabcdabcdabcy";
        string pattern = "abcdabcy";
        cout << text << endl;
        cout << pattern << endl;
        if(KMP(text, pattern))
        {
            cout << "The Pattern is present in the text" << endl;
        }
        else 
        {
            cout << "The Pattern is not present in the text" << endl;
        }
    }
    return 0;
}