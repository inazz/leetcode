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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        deque<TreeNode *> cur, next;
        cur.push_back(root);
        int level = 0;
        while(!cur.empty()) {
            ans.push_back(vector<int>());
            while(!cur.empty()) {
                if (level % 2 == 0) {
                    TreeNode *n = cur.front();
                    cur.pop_front();
                    ans[level].push_back(n->val);
                    if (n->left)
                        next.push_back(n->left);
                    if (n->right)
                        next.push_back(n->right);
                } else {
                    TreeNode *n = cur.back();
                    cur.pop_back();
                    ans[level].push_back(n->val);
                    if (n->right)
                        next.push_front(n->right);
                    if (n->left)
                        next.push_front(n->left);
                }
            }
            swap(cur, next);
            level++;
        }
        return ans;
    }
};
