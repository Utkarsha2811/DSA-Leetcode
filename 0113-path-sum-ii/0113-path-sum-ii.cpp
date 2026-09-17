/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node, int sum, vector<int> path) {
        if (node == NULL) {
            return;
        }

        path.push_back(node->val);
        sum = sum - node->val;

        if (node->left == NULL && node->right == NULL && sum == 0) {
            result.push_back(path);
        } else {
            dfs(node->left, sum, path);
            dfs(node->right, sum, path);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};