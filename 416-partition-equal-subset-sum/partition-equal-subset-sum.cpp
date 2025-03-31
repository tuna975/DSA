class Solution {
public:
bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0){
        return true;
    }
    if(i==0){
        return k == arr[i];
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    bool noPick = solve(i-1, k, arr, dp);
    bool pick = false;
    if(k>=arr[i]){
        pick = solve(i-1, k-arr[i], arr, dp);

    } 

    return dp[i][k] = (noPick || pick);


}
    bool canPartition(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++)
        {
            k += nums[i];
        }
        if(k%2==1){
            return false;
        }
        int k1 = k/2;
        vector<vector<int>> dp(n, vector<int>(k1+1, -1));
        return solve(n-1, k1, nums, dp);

        
    }
};