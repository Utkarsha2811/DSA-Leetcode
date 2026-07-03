class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<pair<int,int>> adj[n];

        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<vector<int>> q;

        q.push({0,src,0});

        vector<int> dist(n,INT_MAX);

        dist[src]=0;

        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();

            int cost=cur[0];
            int node=cur[1];
            int stops=cur[2];

            if(stops>k)
                continue;

            for(auto &it:adj[node])
            {
                int next=it.first;
                int price=it.second;

                if(cost+price<dist[next])
                {
                    dist[next]=cost+price;
                    q.push({dist[next],next,stops+1});
                }
            }
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};