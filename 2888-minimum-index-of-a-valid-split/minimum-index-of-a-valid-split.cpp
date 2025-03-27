class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;

        int el = 0;
        int cnt = 0;
        int n = nums.size();

        for (int it : nums) {
            mp[it]++;
        }

        for (auto& [it, c] : mp) {
            if (c > n / 2) {
                el = it;
                cnt = c;
                break;
            }
        }

        int lc = 0;
        for (int i = 0; i < n - 1; i++) {

            if (nums[i] == el){
                lc++;
            }

            int ls = i + 1;
            int rs = n - ls;
            int rc = cnt - lc;

            if (lc > ls / 2 && rc > rs / 2) {
                return i;
            }
        }

        return -1;
    }
};