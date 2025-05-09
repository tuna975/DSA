class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i<=n; i++){
            string s = ans;
            int len = s.size();
            int j = 0;
            ans = "";

            while(j<len)
            {
                int k = j;
                while(j<len && s[j] == s[k])
                {
                    k++;
                }

                ans += to_string(k - j) + (s[j]);
                j = k;
            }
        }

        return ans;
    }
};