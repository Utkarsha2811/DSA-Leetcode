class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>& image,int oldcolor,int newcolor){

        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size()){
            return;
        }

         // color check
        if (image[r][c] != oldcolor)
            return;

        // change color
        image[r][c] = newcolor;

        dfs(r + 1, c, image, oldcolor, newcolor); // down
        dfs(r - 1, c, image, oldcolor, newcolor); // up
        dfs(r, c + 1, image, oldcolor, newcolor); // right
        dfs(r, c - 1, image, oldcolor, newcolor); // left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];

        if(oldcolor == color){
            return image; // avoid infinite recursion 
        }

        dfs(sr,sc,image,oldcolor,color);
        return image;

    }
};