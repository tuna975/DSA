class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> mp;

        if(n%groupSize != 0)
        {
            return false;
        }

        for(auto it: hand)
        {
            mp[it]++;
        }


        while(n--)
        {
            for(auto [a,b] : mp)
            {
                for(int i = a; i< a+groupSize; i++)
                {
                    if(mp[i] == 0)
                    {
                        return false;
                    }
                    mp[i]--;
                    if(mp[i] == 0)
                    {
                        mp.erase(i);
                    }
                }
                break;
            }
        }

        return true;
    }
};