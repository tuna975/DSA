class Solution {
public:

    int rec(int idx, int t, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(idx == 0)
        {
            if(t%coins[0] == 0)
            {
                return t/coins[0];
            }
            else{
                return 1e9;
            }
        }

        if(dp[idx][t] != -1)
        {
            return dp[idx][t];
        }

        int notPick = 0 + rec(idx -1, t, coins,dp);
        int pick = INT_MAX;
        if(coins[idx]<=t)
        {
            pick = 1 + rec(idx, t - coins[idx], coins, dp);
        }
        return dp[idx][t] = min(pick, notPick);
    }



    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = rec(n-1, amount, coins, dp);
        if(ans>= 1e9) return -1;


        return ans;
    }
};