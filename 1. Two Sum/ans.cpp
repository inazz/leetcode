class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_idx;
        for (int i=0; i<nums.size(); i++)
            num_idx[nums[i]] = i;
        for (int i=0; i<nums.size(); i++) {
            map<int, int>::iterator itr = num_idx.find(target - nums[i]);
            if (itr != num_idx.end() && itr->second != i) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(itr->second);
                return ans;
            }
        }
        throw "unexpected: no answer";
    }
};
