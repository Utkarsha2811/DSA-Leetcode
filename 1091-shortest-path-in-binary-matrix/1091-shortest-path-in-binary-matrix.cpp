class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //base case
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){ //means the route is block
            return -1;
        }

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1; // at start the dist will be 1
        
        // to search neighbours in all directions 
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int dist = grid[r][c];
            if(r == n-1 && c == n-1){
                return dist;
            }

            // lets go to the neighbours and add them in the queue if any 0
            for(int i = 0; i < 8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                // writing all the conditions
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    q.push({nr,nc});
                    grid[nr][nc] = dist + 1;
                }

            }
        }
        return -1;

    }
};