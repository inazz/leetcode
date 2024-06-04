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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    TreeNode* sortedArrayToBST(const vector<int>& nums, int low_index, int high_index) {
        if (low_index == high_index)
            return nullptr;
        int mid_index = low_index + (high_index - low_index) / 2;
        return new TreeNode(
            nums[mid_index],
            sortedArrayToBST(nums, low_index, mid_index),
            sortedArrayToBST(nums, mid_index+1, high_index));
    }
};
