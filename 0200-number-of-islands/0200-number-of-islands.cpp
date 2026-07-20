class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid){
        // always set the boundary first
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return;
        }
        if(grid[r][c] == '0'){
            return;
         }
        grid[r][c] = '0'; // most imp mark it as visited 

        dfs(r + 1, c, grid); // down
        dfs(r - 1, c, grid); // up
        dfs(r, c + 1, grid); // right
        dfs(r, c - 1, grid); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};