class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r){
            int w = r - l;
            int ht = min(height[l],height[r]);
            int curr = w * ht;
            maxwater = max(maxwater,curr);

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxwater;
    }
};