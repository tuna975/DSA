class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int num = nums[0];

        int profit = 0;

        for(int i = 1; i<nums.size(); i++)
        {
            if(num > nums[i])
            {
                num = nums[i];


            }

            profit = max(profit, nums[i] - num);
        }

        bool flag = false;

        for(int i = 0; i<nums.size()-1; i++)
        {
            if(nums[i+1] > nums[i])
            {
                flag = true;
            }
        }

        if(flag)
        {
            return profit;
        }

        return -1;
    }
};