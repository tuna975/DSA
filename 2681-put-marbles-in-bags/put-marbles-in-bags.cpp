class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> a;

        for(int i =0; i<n-1; i++)
        {
            a.push_back(weights[i] + weights[i+1]);
        }

        sort(a.begin(), a.end());

        long long maxi = 0;
        long long mini = 0;

        for(int i = 0; i<k-1; i++)
        {
            maxi += a[n-2-i];
            mini += a[i];
        }

        long long res = maxi - mini;
        return res;


    }
};