class Solution {
public:

    bool solve(vector<int>& nums, int k, int mid)
    {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n;i++)
        {
            if(nums[i] <= mid)
            {
                cnt++;
                i++;
            }
        }

        return cnt>=k;
    }


    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int mid;

        int ans =  0;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(solve(nums, k, mid))
            {
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};