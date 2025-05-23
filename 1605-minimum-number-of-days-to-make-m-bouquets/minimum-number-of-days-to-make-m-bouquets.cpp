class Solution {
public:

    bool help(vector<int> &nums, int mid, int m, int k)
    {
        int cnt = 0;
        int b = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] <= mid)
            {
                cnt++;
            }
            else{
                b += cnt/k;
                cnt = 0;
            }
        }

        b += cnt/k;
        return b >=m;
    }
    int minDays(vector<int>& nums, int m, int k) {

        
        int low = INT_MAX;
        int high = INT_MIN;

        int n = nums.size();
        long long val = m*1LL*k*1LL;

        if(n < val)
        {
            return -1;
        }

        for(int i = 0; i<n; i++)
        {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }

        while(low<=high)
        {
            int mid = (low + high)/2;
            if(help(nums, mid, m, k))
            {
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }

        return low;
    }
};