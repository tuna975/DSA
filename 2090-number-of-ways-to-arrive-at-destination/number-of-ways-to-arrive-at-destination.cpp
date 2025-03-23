class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];

        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, 1e15);
        vector<long> arr(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        arr[0] = 1;

        pq.push({0, 0});
        int mod = (int)(1e9 + 7);

        while(!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;


            pq.pop();

            for(auto it : adj[node])
            {
                int adjNode = it.first;
                long long edW = it.second;

                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    arr[adjNode] = arr[node];
                    pq.push({dis + edW, adjNode});
                }
                else if(dis + edW == dist[adjNode])
                {
                    arr[adjNode] = (arr[adjNode] + arr[node]) % mod;
                }
            }

        }

        return (arr[n-1] % mod);
    }
};