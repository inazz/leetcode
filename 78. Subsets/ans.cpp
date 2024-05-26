class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int n = 0; n < (1<<nums.size()); n++) {
            vector<int> subset;
            for (int i = 0; i < nums.size(); i++) {
                if (n & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
