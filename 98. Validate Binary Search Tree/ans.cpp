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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode* root, TreeNode *left, TreeNode *right) {
        if (!root)
            return true;
        if ((left  && !(left->val < root->val)) ||
            (right && !(root->val < right->val)))
            return false;
        return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
};
