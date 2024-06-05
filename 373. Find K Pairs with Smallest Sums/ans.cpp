class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const vector<int> *nums[2] = {&nums1, &nums2};
        vector<vector<int>> ans;
        set<pair<int, pair<int, int>>> s;// pair(sum, pair(idx1, idx2))
        s.insert(make_pair(nums1[0]+nums2[0], make_pair(0, 0)));
        while(s.size() && ans.size() < k) {
            auto itr = s.begin();
            int indices[2] = {itr->second.first, itr->second.second};
            s.erase(itr);
            vector<int> new_ans(2, 0);
            new_ans[0] = nums1[indices[0]];
            new_ans[1] = nums2[indices[1]];
            ans.push_back(new_ans);
            for (int i = 0; i < 2; i++) {
                if (indices[i] == nums[i]->size() - 1)
                    continue;
                indices[i]++;
                s.insert(make_pair(nums1[indices[0]]+nums2[indices[1]],
                                   make_pair(indices[0], indices[1])));
                indices[i]--;
            }
        }
        return ans;
    }
};
