class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = k - 1;

        double sum = 0;

        for(int i = l; i <= r; i++){
            sum += nums[i];
        }

        double maxi = sum;

        while(r < n-1){
            sum = sum - nums[l];
            l++;

            r++;
            sum = sum + nums[r];

            maxi = max(sum,maxi);
        }

        return maxi / k;
    }
};