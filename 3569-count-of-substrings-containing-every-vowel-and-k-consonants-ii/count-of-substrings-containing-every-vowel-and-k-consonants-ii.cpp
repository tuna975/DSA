
class Solution {
public:
    set<char> st { 'a', 'e', 'i', 'o', 'u' };
    bool containsAllst(map<char, int>& mp) {
        for (const char& c : st)
            if (mp[c] == 0)
                return false;
        return true;
    }

    long long countOfSubstrings(string word, int k) {
        long long res = 0, n = word.size(), cnt = 0, str = 0;
        map<char, int> mp;
        for (int i = 0, j = 0; i < n; i++) {
            if (st.contains(word[i]))
                mp[word[i]]++;
            else
                cnt++;
        
            while (cnt > k) {
                if (st.contains(word[j]))
                    mp[word[j]]--;
                else
                    cnt--;
                str = ++j;
            }
         
            while (st.contains(word[j]) && mp[word[j]] > 1)
                mp[word[j++]]--;
            if (containsAllst(mp) && cnt == k) {
                res++;
                res += j - str;
            }
        }
        return res;
    }
};