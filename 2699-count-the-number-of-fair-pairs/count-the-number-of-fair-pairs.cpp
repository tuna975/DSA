class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long cnt = 0;

        for(int i = 0; i<n-1; i++)
        {
            int low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();

            cnt += (high - low);
        }

        return cnt;
    }
};