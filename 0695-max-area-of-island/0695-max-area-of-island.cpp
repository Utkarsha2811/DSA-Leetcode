class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,int &cnt){
        // always set the boundary first
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return;
        }
        if(grid[r][c] == 0){
            return;
         }
        grid[r][c] = 0;
        cnt++; 

        dfs(r + 1, c, grid,cnt); // down
        dfs(r - 1, c, grid,cnt); // up
        dfs(r, c + 1, grid,cnt); // right
        dfs(r, c - 1, grid,cnt); // left
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i,j,grid,cnt);
                    maxi = max(cnt,maxi);
                }
            }
        }
        return maxi;
    }
};