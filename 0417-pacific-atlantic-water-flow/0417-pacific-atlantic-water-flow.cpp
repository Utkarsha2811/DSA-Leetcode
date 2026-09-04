class Solution {
public:
int m, n;
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        
        // 4 possible directions: down, up, right, left
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            // Check boundaries, ensure it hasn't been visited, 
            // and verify that the water can flow upward (next height >= current height)
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // Run DFS for the top and bottom rows
        for (int c = 0; c < n; c++) {
            dfs(heights, pacific, 0, c);       // Top edge (Pacific)
            dfs(heights, atlantic, m - 1, c);   // Bottom edge (Atlantic)
        }
        
        // Run DFS for the left and right columns
        for (int r = 0; r < m; r++) {
            dfs(heights, pacific, r, 0);       // Left edge (Pacific)
            dfs(heights, atlantic, r, n - 1);   // Right edge (Atlantic)
        }
        
        // Find all coordinates that can reach both oceans
        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
};