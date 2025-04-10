class Solution {
public:
    int rec(int i, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(i == nums.size()){
            if(target == 0)
                return 1;   
            else
                return 0;  
        }

        
        if(dp[i][target+2000] != -1) return dp[i][target+2000];


      
        int add = rec(i+1, nums, target - nums[i], dp);
        int subtract = rec(i+1, nums, target + nums[i], dp);

        return dp[i][target+2000] = add + subtract;
            
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        vector<vector<int>> dp(nums.size() + 1, vector<int>(5005, -1));
        return rec(0, nums, target, dp);
    }
};