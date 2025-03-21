class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> in;
        for (int i = 0; i < recipes.size(); ++i) {
            for (auto& it : ingredients[i]) {
                g[it].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }
        
        queue<string> q;
        for (auto& s : supplies) q.push(s);

        
        unordered_set<string> st;
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (auto& it : g[cur]) {
                if (--in[it] == 0) {
                    q.push(it);
                    st.insert(it);
                }
            }
        }
        
        vector<string> res;
        for (auto& it : recipes)
            if (st.count(it))
                res.push_back(it);
        return res;
    }
};