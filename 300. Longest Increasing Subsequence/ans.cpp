class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> data;
        for (int i = 0; i < nums.size(); i++) {
            set<int>::iterator itr = data.lower_bound(nums[i]);
            if (itr == data.end()) {
                data.insert(nums[i]);
            } else {
                data.erase(itr);
                data.insert(nums[i]);
            }
        }
        return data.size();
    }
    int lengthOfLIS_N2(vector<int>& nums) {
        vector<int> tbl(nums.size());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            tbl[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    tbl[i] = max(tbl[i], tbl[j] + 1);
                }
            }
            ans = max(ans, tbl[i]);
        }
        return ans;
    }
};
