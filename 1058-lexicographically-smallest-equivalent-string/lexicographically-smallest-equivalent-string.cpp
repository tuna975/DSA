class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       
        int n = s1.size();
        vector<char> ref(26);
        for (int i = 0; i < 26; i++)
            ref[i] = 'a' + i;
    
        for (int i = 0; i < n; i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            char lb = max(ref[a], ref[b]);
            char ls = min(ref[a], ref[b]);
            for (auto& it : ref)
                if (it == lb)
                    it = ls;
        }
        for (char& c : baseStr) {
            c = ref[c - 'a'];
        }
        return baseStr;
    }
};