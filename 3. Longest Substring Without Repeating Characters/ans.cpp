class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left_idx = 0;
        int ans = 0;
        vector<bool> used(128, false);
        for (int i = 0; i < s.size(); i++) {
            while (used[s[i]]) {
                used[s[left_idx]] = false;
                left_idx ++;
            }
            used[s[i]] = true;
            ans = max(ans, i - left_idx + 1);
        }
        return ans;
    }
};
