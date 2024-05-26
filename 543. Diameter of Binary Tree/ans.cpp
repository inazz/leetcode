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

struct TreeAttribute {
    int depth;
    int diameter;
    TreeAttribute() {
        this->depth = this->diameter = 0;
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return calculateTreeAttribute(root).diameter;
    }
    TreeAttribute calculateTreeAttribute(TreeNode *node) {
        TreeAttribute leftAttr, rightAttr;
        if (node->left != nullptr) {
            leftAttr = calculateTreeAttribute(node->left);
            leftAttr.depth += 1;
        }
        if (node->right != nullptr) {
            rightAttr = calculateTreeAttribute(node->right);
            rightAttr.depth += 1;
        }
        TreeAttribute ans;
        ans.depth = max(leftAttr.depth, rightAttr.depth);
        ans.diameter = max(leftAttr.depth + rightAttr.depth,
                           max(leftAttr.diameter, rightAttr.diameter));
        return ans;
    }
};
