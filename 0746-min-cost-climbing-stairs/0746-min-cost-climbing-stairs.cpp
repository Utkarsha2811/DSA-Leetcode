class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int down_one = 0;
        int down_two = 0;
        
        // Iterate from step 2 up to the top of the floor (n)
        for (size_t i = 2; i <= cost.size(); ++i) {
            int current = std::min(down_one + cost[i - 1], down_two + cost[i - 2]);
            down_two = down_one;
            down_one = current;
        }
        
        return down_one;
    }
};