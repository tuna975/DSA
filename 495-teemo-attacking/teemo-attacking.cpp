class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        sort(timeSeries.begin(), timeSeries.end());
        int n = timeSeries.size();

        int cnt = 0;
        for(int i =0; i<n-1; i++)
        {
            int time = timeSeries[i+1] - timeSeries[i];
            cnt += min(time, duration);
        }

        cnt += duration;

        return cnt;
    }
};