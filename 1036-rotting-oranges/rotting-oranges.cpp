class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        queue<pair<pair<int,int>, int>> q;

        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }


        int cnt = 0;

        vector<int> xs = {1, 0, -1, 0};
        vector<int> xy = {0, 1, 0, -1};

        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;

            q.pop();


            cnt = max(cnt, t);


            for(int i =0; i<4; i++)
            {
                int x1 = x + xs[i];
                int y1 = y + xy[i];

                if(x1 >= 0 && x1 <n && y1 >=0 && y1 <m && vis[x1][y1] == 0 && grid[x1][y1] == 1)
                {
                    q.push({{x1,y1}, t+1});
                    vis[x1][y1] = 1;
                    grid[x1][y1] = 2;
                }
            }
        }


        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return cnt;


    }
};