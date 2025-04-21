class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long pre = 0;
        long long mini = 0, maxi = 0;
        
        for (int it : differences) {
            pre += it;
            mini = min(mini, pre);
            maxi = max(maxi, pre);
        }

        long long mins = lower - mini;
        long long maxs = upper - maxi;


       
        return max(maxs-mins+1,0LL);
    }
};