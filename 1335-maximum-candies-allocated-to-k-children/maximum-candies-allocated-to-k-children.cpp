#define ll long long

class Solution {
public:

    bool solve(vector<int>& a, ll mid, ll k)
    {
        ll cnt = 0;
        ll n = a.size();

        for(ll i = 0; i<n; i++)
        {
            if(a[i] >= mid)
            {
                cnt += a[i]/mid;
            }
        }

        return cnt >=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        ll l = 1;
        ll r = *max_element(candies.begin(), candies.end());


        ll maxi = 0;

        while(l<=r)
        {
            ll mid = l + (r-l)/2;
            if(solve(candies, mid, k))
            {
                maxi = mid;
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }

        return maxi;


    }
};