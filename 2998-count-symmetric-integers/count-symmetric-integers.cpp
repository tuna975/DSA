class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i<= high; i++)
        {
            string s = to_string(i);
            if(s.length()%2 == 1)
            {
                continue;
            }
            int first = 0;
            int second = 0;

            for(int i = 0; i<(s.length()/2); i++)
            {
                first += (s[i] - '0');
                second += (s[s.length() -i -1] - '0');
            }

            if(first == second)
            {
                cnt++;
            }
        }

        return cnt;
    }
};