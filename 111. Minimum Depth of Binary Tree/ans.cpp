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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ans = -1;
        if (root->left) {
            ans = minDepth(root->left) + 1;
        }
        if (root->right) {
            int right_ans = minDepth(root->right) + 1;
            ans = (ans == -1 ? right_ans : min(ans, right_ans));
        }
        return (ans == -1 ? 1 : ans);
    }
};
