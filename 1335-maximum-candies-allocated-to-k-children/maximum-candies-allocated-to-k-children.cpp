class Solution {
public:

    bool solve(long long& mid, vector<int>& candies, long long& k)
    {
        long long cnt = 0;

        for(auto it : candies)
        {
            if(it >= mid)
            {
                cnt += it/mid;
            }
        }

        return cnt >= k;
    }


    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        long long mid;


        long long maxi = 0;

        while(low<=high)
        {   
            long long mid = low + (high-low)/2;
            if(solve(mid, candies, k))
            {
                maxi = mid;
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }

        return maxi;
    }
};