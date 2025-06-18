class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});


        }


        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0, {src, 0}});

        vector<int> dis(n, 1e9);
        dis[src] = 0;


        while(!pq.empty())
        {
            auto iter = pq.top();
            pq.pop();

            int stops = iter.first;
            int node = iter.second.first;
            int dist = iter.second.second;

            if(stops > k)
            {
                continue;
            }

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw = it.second;


                if(dist + edw < dis[adjNode] && stops <= k)
                {
                    dis[adjNode] = dist + edw;
                    pq.push({stops+1, {adjNode,dist+edw}});
                }
            }
        }

        if(dis[dst] == 1e9)
        {
            return -1;
        }
        else{
            return dis[dst];
        }
    }
};