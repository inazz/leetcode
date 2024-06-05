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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorder_map;
        for(int i=0; i<inorder.size(); i++)
            inorder_map[inorder[i]] = i;
        return buildTree(preorder, inorder, inorder_map, 0, preorder.size(), 0, inorder.size());
    }
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder, const map<int, int> &inorder_map,
                        int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left == preorder_right)
            return nullptr;
        int val = preorder[preorder_left];
        const int inorder_idx = inorder_map.at(val);
        int num_left = inorder_idx - inorder_left;
        return new TreeNode(
            val,
            buildTree(preorder, inorder, inorder_map, preorder_left+1, preorder_left+1+num_left, inorder_left, inorder_idx),
            buildTree(preorder, inorder, inorder_map, preorder_left+num_left+1, preorder_right, inorder_idx+1, inorder_right));
    }
};
