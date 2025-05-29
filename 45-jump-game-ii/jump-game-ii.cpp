class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int f =0;

        int j = 0;

        while(r<n-1)
        {
            for(int i = l; i<=r; i++)
            {
                f = max(f, i + nums[i]);
            }

           l = r+1;
          r = f;

            j++;

        }

        return j;




    }
};