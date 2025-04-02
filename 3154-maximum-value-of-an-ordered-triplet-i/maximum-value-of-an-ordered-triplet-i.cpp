class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mt = 0;
        long long me = 0;
        long long md = 0;

        for (long long it : nums) {
            mt = max(mt, md * it);
            md = max(md, me - it);
            me = max(me, it);
        }
        return mt;
    }
};