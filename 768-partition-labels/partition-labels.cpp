class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;

        for(int i = 0; i<s.size(); i++)
        {   
            mp[s[i]] = i;
        }

        int prev = -1;
        int maxi = 0;

        vector<int> ans;

        for(int i= 0; i<s.size(); i++)
        {
            maxi = max(maxi, mp[s[i]]);
            if(maxi == i)
            {
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }

        return ans;
    }
};