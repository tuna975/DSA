class Solution {
public:

    int f(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(n<0)
        {
            return m + 1;
        }

        if(m<0)
        {
            return n+1;
        }

        if(dp[n][m]!= -1)
        {
            return dp[n][m];
        }

        if(s1[n] == s2[m])
        {
            return dp[n][m] = f(n-1, m-1, s1, s2, dp);
        }
        
        return dp[n][m] =  1 + min(f(n-1, m, s1, s2, dp), min(f(n, m-1, s1, s2, dp), f(n-1, m-1, s1, s2, dp)));
    }



    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n,m, word1, word2, dp);
    }
};