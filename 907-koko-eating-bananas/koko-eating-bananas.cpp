class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1;
        int hi = *max_element(piles.begin(), piles.end());

        

        while(l<=hi)
        {
            int mid = (l + hi)/2;
            long long cnt = 0;

            for(int i = 0; i<n; i++)
            {
                if(piles[i] <= mid)
                {
                    cnt += 1;
                }
                else if(piles[i]%mid == 0)
                {
                    cnt += piles[i]/mid;
                }
                else{
                    cnt += (piles[i]/mid) + 1;
                }
            }

            if(cnt <= h)
            {
                hi = mid -1;
            }
            else{
                 l = mid +1;
            }
        }

        return l;
    }
};