class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int el = 1;
        for (int n : nums) {
            if (n > 0 && n == el) {
                el++;
            } else if (n > el) {
                return el;
            }
        }

        return el;
    }
};