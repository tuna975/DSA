class Solution {
public:
    
    int rec(int idx, int t, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(idx == 0)
        {
            if(t%coins[0] == 0)
            {
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[idx][t] != -1)
        {
            return dp[idx][t];
        }

        int notPick = rec(idx -1, t, coins,dp);
        int pick = 0;
        if(t>=coins[idx])
        {
            pick =  rec(idx, t - coins[idx], coins, dp);
        }
        return dp[idx][t] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = rec(n-1, amount, coins, dp);
        return ans;
    }
};