class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n-1) return triangle[i][j];

        int down = triangle[i][j] + helper(i+1, j, triangle, n, dp);
        int dg = triangle[i][j] + helper(i+1, j+1, triangle, n, dp);

        return dp[i][j] = min(down, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, 0, triangle, n, dp);
    }
};