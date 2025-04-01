class Solution {
public:

    long long f(int idx,  vector<long long>& dp,vector<vector<int>>& a){
        int n = a.size();
        if(idx >= n)
        {
            return 0;
        }

        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        long long take = a[idx][0] + f(idx + a[idx][1] +1, dp, a);
        long long notTake = f(idx+1, dp, a);

        return dp[idx] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return f(0, dp, questions);
    }
};