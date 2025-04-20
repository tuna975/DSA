class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;

        for(int it : answers){
            mp[it]++;
        }


        int total = 0;

        for(auto it : mp)
        {
            int gr = it.first;
            int cnt = it.second;

            int grp = ceil((double)cnt/(gr+1));
            total += grp*(gr+1);
        }

        return total;
    }
};