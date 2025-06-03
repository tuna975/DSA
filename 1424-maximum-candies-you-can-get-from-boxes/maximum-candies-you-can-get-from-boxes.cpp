class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();


        queue<int> q;

        for(auto it : initialBoxes)
        {
            q.push(it);
        }

        unordered_set<int> st;
        int tot = 0;


        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(status[curr] == 0)
            {
                st.insert(curr);
                continue;
            }


            for(auto it : keys[curr])
            {
                status[it] = 1;
                if(st.count(it))
                {
                    q.push(it);
                    st.erase(it);
                }
            }


            tot += candies[curr];

            for(auto it : containedBoxes[curr])
            {
                q.push(it);
            }
        }

        return tot;
    }
};