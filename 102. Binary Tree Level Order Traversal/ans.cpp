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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, 0, &ans);
        return ans;
    }
    void levelOrder(TreeNode *root, int level, vector<vector<int>> *out) {
        if (root == nullptr)
            return;
        while (out->size() <= level)
            out->push_back(vector<int>());
        (*out)[level].push_back(root->val);
        levelOrder(root->left, level+1, out);
        levelOrder(root->right, level+1, out);
    }
};
