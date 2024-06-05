class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int idx1 = 0, idx2 = 0;
        vector<int> ans;
        while(idx1 < nums1.size() && idx2 < nums2.size()) {
            int n1 = nums1[idx1], n2 = nums2[idx2];
            if (n1 == n2)
                ans.push_back(n1);
            if (n1 <= n2) {
                while (idx1 < nums1.size() && nums1[idx1] == n1)
                    idx1++;
            }
            if (n1 >= n2) {
                while (idx2 < nums2.size() && nums2[idx2] == n2)
                    idx2++;
            }
        }
        return ans;
    }
};
