class Solution {
public:
int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int robb = nums[i] + solve(i + 2, nums, dp);
        int skip = solve(i + 1, nums, dp);

        return dp[i] = max(robb, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        
        vector<int> a(nums.begin(),nums.end() - 1);
        vector<int> b(nums.begin() + 1,nums.end());

        vector<int> dp1(a.size(),-1);
        vector<int> dp2(b.size(),-1);

        return max(solve(0,a,dp1),solve(0,b,dp2));

    }
};