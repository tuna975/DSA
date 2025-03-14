class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        vector<int> res(n, 0);


        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(baskets[j] >= fruits[i] && res[j] != 1)
                {
                    res[j] = 1;
                    break;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i<n; i++)
        {
            if(res[i] == 0)
            {
                cnt++;
            }
        }

        return cnt;
    }
};