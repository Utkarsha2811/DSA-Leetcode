class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; // we take the set to store the unique characters 

        int l = 0;
        int ans = 0; 

        for(int r = 0; r < s.size(); r++){
            while(st.count(s[r])){ // if the char already exits in the set then ...
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);

            ans = max(ans,r-l+1);
        }

        return ans;
    }
};