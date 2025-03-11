class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        vector<int> res(3, -1);

        int cnt = 0;

        for(int i = 0; i<n;i++)
        {
            res[s[i] - 'a'] = i;

            if(res[0] != -1 && res[1] !=-1 && res[2] != -1)
            {
                cnt += (1 + min({res[0],res[1],res[2]}));
            }
        }

        return cnt;
    }
};