class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int ans = 0;

        sort(meetings.begin(), meetings.end());
        int l = 1;

        for(int i = 0; i<n; i++)
        {
            int s = meetings[i][0];
            int e = meetings[i][1];

            if(s>l)
            {
                ans+= (i==0) ? (s-l) : (s-l-1);
            }
            l = max(l, e);
        }

        if(days > l){
            ans += days - l;
        }

        return ans;


    }
};