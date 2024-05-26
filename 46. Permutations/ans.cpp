class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate_permutation(nums, 0, &ans);
        return ans;
    }
    void generate_permutation(vector<int> nums, int level, vector<vector<int>> *out) {
        if (level == nums.size()) {
            out->push_back(nums);
            return;
        }
        for (int i=level; i<nums.size(); i++) {
            swap(nums[level], nums[i]);
            generate_permutation(nums, level+1, out);
            swap(nums[level], nums[i]);
        }
    }
};
