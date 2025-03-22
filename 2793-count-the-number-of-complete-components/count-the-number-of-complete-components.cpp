class Solution {
    void dfs(int curr,int& nd,int& ed,vector<vector<int>>& adj,vector<bool>& vis){
        nd++;
        vis[curr] = true;
        for(int& it: adj[curr]){
            ed++;
            if(!vis[it])
                dfs(it,nd,ed,adj,vis);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;++i){
            if(!vis[i]){
               
                int ed = 0;
                int nd = 0;
                dfs(i,nd,ed,adj,vis);
                
                if(ed==(nd*(nd-1)))
                    cnt++;
            }
        }
        return cnt;
    }
};