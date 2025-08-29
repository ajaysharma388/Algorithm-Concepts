class Solution {
public:
    int longestPalindromeSubseq(string s) {
             int n = s.size();
        // shortcuts
        if (n == 1)
            return 1;
        if (n == 2)
            return s[0] == s[1] ? 2 : 1;
        // total palindromic
        int l = 0, r = s.size() - 1;
        while (l <= r){
            if (s[l] != s[r])
                break;
            l++, r--;
        }
        if (l > r)
            return n;
        
        // dp O(n) solution
        vector<int> dp(n, 0);
        for (int i = n-2; i >= 0; i--) // i is the starting index of the substr
        {
            int hold = 0;                   // hold = 0 since empty string has len 0
            dp[i] = 1;                      // i to i is palin with len 1
            for (int j = i+1; j < n; j++) // j is the ending index of the substr, i != j
            {  
                int temp = dp[j];
                // main dp statement see last submitted solution though at solution is saved with len and start, the idea is the same, dp using start end will require looping reversely from end to start
                if (s[i] == s[j])
                    dp[j] = 2 + hold; // hold = dp[i+1][j-1];
                else
                    dp[j] = max(dp[j], dp[j-1]); // max(dp[i+1][j], dp[i][j-1]);
                hold = temp;
            }
        }
        return dp[n-1];
   
    }
};