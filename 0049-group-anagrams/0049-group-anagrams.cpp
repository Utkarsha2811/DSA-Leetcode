class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp; // ek box banvla mp it stores string aani vector of strings like one word (string) → many words (vector of strings)

        for(int i = 0; i < strs.size(); i++){// check each word
              string key = strs[i]; // curr word la copy kel 
              sort(key.begin(),key.end()); // words la sort kel so easily same words la eka group madhe taku shakto
              mp[key].push_back(strs[i]); // This line finds the correct group and puts the word inside it.
        }
        vector<vector<string>> ans;   // to store the answer

        for (auto it : mp) { // go through each grp 
            ans.push_back(it.second); // take only words ignore key (it.first)
        }
        return ans;

    }
};