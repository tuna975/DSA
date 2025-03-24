class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<array<int,3>> a(n);
        for(int i = 0; i<n; i++)
        {
            a[i] = {nums1[i], nums2[i], i};
        }

        sort(a.begin(), a.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<long long> res(n);
        long long sum = 0;


        for(int i =0; i<n; i++)
        {
            if(i>0 && a[i-1][0] == a[i][0])
            {
                res[a[i][2]] = res[a[i-1][2]];
            }
            else{
                res[a[i][2]] = sum;
            }


            pq.push(a[i][1]);
            sum += a[i][1];

            if(pq.size() >k)
            {
                sum -= pq.top();
                pq.pop();
            }
        }

        return res;
    }
};