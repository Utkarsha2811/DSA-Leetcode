class Solution {
private:
    void dfs(int node, vector<vector<int>>& list, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : list[node]) {
            if (!vis[it]) {
                dfs(it, list, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // adjacency list
        vector<vector<int>> list(V);

        // convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (isConnected[i][j] == 1) {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, list, vis);
            }
        }

        return cnt;
    }
};