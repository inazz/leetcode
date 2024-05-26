class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> used;
        searchDfs(candidates, target, 0, 0, &used, &ans);
        return ans;
    }
    void searchDfs(const vector<int> &candidates, int target, int level,
                   int currentSum, vector<int> *used, vector<vector<int>> *out) {
        if (currentSum > target)
            return;
        if (level == candidates.size()) {
            if (currentSum == target)
                out->push_back(*used);
            return;
        }
        searchDfs(candidates, target, level+1, currentSum, used, out);
        used->push_back(candidates[level]);
        searchDfs(candidates, target, level, currentSum+candidates[level], used, out);
        used->pop_back();
    }
};
