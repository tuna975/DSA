class Solution {
public:

    bool solve(vector<int>& nums, int mid, int p)
    {
        int cnt = 0;
        int i = 1;


        while(i<nums.size())
        {
            if(nums[i] - nums[i-1] <= mid)
            {
                cnt++;
                i = i +2;
            }
            else{
                i++;
            }
        }

        return cnt >=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back();

        int ans = INT_MAX;



        while(low<= high)
        {
            int mid = low + (high - low)/2;


            if(solve(nums, mid, p))
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};