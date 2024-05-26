class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left_idx = 0;
        int curSum = 0;
        const int ANS_NOT_FOUND = nums.size() + 1;
        int ans = ANS_NOT_FOUND;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            while(curSum - nums[left_idx] >= target) {
                curSum -= nums[left_idx];
                left_idx++;
            }
            if (curSum >= target)
                ans = min(ans, i - left_idx+1);
        }
        return (ans == ANS_NOT_FOUND ? 0 : ans);
    }
};
