class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>> &graph)
    {
        vis[i] = 1;
        pathVis[i] = 1;
        check[i] = 0;

        for(int j = 0; j<graph[i].size(); j++)
        {
            int it = graph[i][j];

            if(!vis[it])
            {
                if(dfs(it, vis, pathVis, check, graph))
                {
                    check[it] = 0;
                    return true;
                }
            }
            else if(pathVis[it] == 1)
            {
                check[it] = 0;
                return true;
            }
        }

        check[i] =1;
        pathVis[i] = 0;
        return false;
    }




    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();


        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);

        for(int i = 0; i< n; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, pathVis, check, graph);
            }
        }

        vector<int> ans;

        for(int i = 0; i<check.size(); i++)
        {
            if(check[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};