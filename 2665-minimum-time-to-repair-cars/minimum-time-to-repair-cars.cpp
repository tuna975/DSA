#define ll long long


class Solution {
public:

    bool solve(vector<int>& ranks, int cars, ll mid)
    {
        ll cnt = 0;
        for(int i =0; i<ranks.size(); i++)
        {
            cnt += sqrt(mid/ranks[i]);
        }

        return cnt>=cars;
    }



    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1;
        ll r = 1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;



        ll ans = 0;


        while(l<=r)
        {
            ll mid = l + (r-l)/2;
            if(solve(ranks, cars, mid))
            {
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};