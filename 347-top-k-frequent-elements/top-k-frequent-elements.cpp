class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;


        for(auto it : nums)
        {
            mp[it]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }

        vector<int> ans;

        for(int i = 1; i<=k; i++)
        {
            pair<int,int> el = pq.top();
            pq.pop();
            int num = el.second;

            ans.push_back(num);
        }

        return ans;
    }
};