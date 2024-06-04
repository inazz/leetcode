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
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return (targetSum == root->val);
        return ((root->left != nullptr && hasPathSum(root->left, targetSum - root->val)) ||
                (root->right != nullptr && hasPathSum(root->right, targetSum - root->val)));
    }
};
