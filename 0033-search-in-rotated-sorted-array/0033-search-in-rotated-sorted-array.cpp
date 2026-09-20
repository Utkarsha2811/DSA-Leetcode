class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high){

            int mid = (low + high) / 2;

            if(nums[mid] == target){ // mid cya equal asen tr target return karu mid la
                return mid;
            }

            // left side sorted asel tr tithe search karu target la 
            if(nums[low] <= nums[mid]){

                if(nums[low] <= target && target < nums[mid]){  // target hya range madhe aahe ka ??? 
                        high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            
            // right side sorted asel tr tithe search karu target la 
            else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }


        }

        return -1;
    }
};