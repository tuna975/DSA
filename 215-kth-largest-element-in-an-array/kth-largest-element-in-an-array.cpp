class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;


        for(int it : nums)
        {
            pq.push(it);
                    }


        int ans;

        for(int i =0; i<k-1; i++)
        {
            pq.pop();
        }
        ans = pq.top();
        return ans;
    }
};