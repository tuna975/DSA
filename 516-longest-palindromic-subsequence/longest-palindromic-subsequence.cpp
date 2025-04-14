class Solution {
public:
    int rec(int n, int m, string &s, string &t, vector<vector<int>> &dp)
    {
        if(n<0 || m<0) return 0;

        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }

        if(s[n] == t[m])
        {
            return dp[n][m] = 1 + rec(n-1, m-1, s, t, dp);
        }

        return dp[n][m] = max(rec(n-1,m,s,t, dp), rec(n, m-1, s , t, dp));
    }




    int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size();
            int m = text2.size();
            vector<vector<int>> dp(n, vector<int> (m, -1));
            int res = rec(n-1, m-1, text1, text2, dp);
            return res;
    }





    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return longestCommonSubsequence(s, s1);

        

    }
};