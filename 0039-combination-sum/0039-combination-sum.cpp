class Solution {
public:
    void back(vector<int>& candidates, int target, vector<int>& cur,
              vector<vector<int>>& ans, int index) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
           
            cur.push_back(candidates[i]);
            back(candidates, target - candidates[i], cur, ans, i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        back(candidates, target, cur, ans, 0);
        return ans;
    }
};