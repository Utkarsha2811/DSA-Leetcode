class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int prevTwoSteps = 1;
        int prevOneStep = 2;
        int currentWays = 0;
        
        for (int i = 3; i <= n; i++) {
            currentWays = prevOneStep + prevTwoSteps;
            prevTwoSteps = prevOneStep;
            prevOneStep = currentWays;
        }
        
        return prevOneStep;
    }
};