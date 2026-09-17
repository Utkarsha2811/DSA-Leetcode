/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }

        if(root->left == NULL && root->right == NULL){
            return  root->val == targetSum;
        }

        int newtarget = targetSum - root->val;

        bool left = hasPathSum(root->left,newtarget);
        bool right = hasPathSum(root->right,newtarget);

        return left || right;
        

    }
};