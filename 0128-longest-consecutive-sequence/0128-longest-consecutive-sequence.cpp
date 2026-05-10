class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int cnt = 1;          // current sequence length
        int longest = 1;      // longest sequence found

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) continue; // skip duplicates

            if(nums[i] == nums[i-1] + 1){
                cnt++;
            } else {
                longest = max(longest, cnt);
                cnt = 1; // reset count
            }
        }
        return max(longest, cnt);
    }
};