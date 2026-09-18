class Solution {
public:
    
    int findfirst(vector<int>& nums, int target){ 
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1; // left la search karu kuthe aahe ka target mage 
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int findlast(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1; // right la search karu kuthe aahe ka target pudhe 
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = findfirst(nums,target);
        int second = findlast(nums,target);

        return {first,second};
    }
};