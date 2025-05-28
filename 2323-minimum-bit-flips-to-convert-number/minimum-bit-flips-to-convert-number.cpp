class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;

        int cnt = __builtin_popcount(ans);
        return cnt;
    }
};