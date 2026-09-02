class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp; // we will use hashmap here to store nums and their index 

        for(int i = 0; i < nums.size(); i++){
            int num = target - nums[i]; // target - nums[i] is our logic 

            if(mp.find(num) != mp.end()){ // if we find num in the hash 
                return {mp[num], i}; // return ithe indexex
            }
            //else we will wtore it in the hashmap ..nums[i] and its index 
            mp[nums[i]] = i; 
        }

        return {}; // if we find no pairs we will return this 
    }
};