class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int num = 0;
        int i;

        for(i = 0; i<n; i++)
        {
            if(nums[i] != i)
            {
                num = i;
                break;

            }
        }

        if(num != 0)
        {
            return num;
        }
        else{
            return i;
        }
    }
};