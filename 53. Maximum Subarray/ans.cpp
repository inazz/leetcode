
struct RangeResult{
    int rightRun;
    int leftRun;
    int sum;
    int best;
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_DC(nums, 0, nums.size()-1).best;
    }
    RangeResult maxSubArray_DC(const vector<int> &nums, int leftIndex, int rightIndex) {
        RangeResult ans;
        if (leftIndex == rightIndex) {
            ans.rightRun = nums[leftIndex];
            ans.leftRun = nums[leftIndex];
            ans.sum = nums[leftIndex];
            ans.best = nums[leftIndex];
            return ans;
        }
        int midIndex = leftIndex + (rightIndex - leftIndex + 1) / 2 - 1;
        RangeResult r = maxSubArray_DC(nums, leftIndex, midIndex);
        RangeResult l = maxSubArray_DC(nums, midIndex+1, rightIndex);
        ans.rightRun = max(r.rightRun, r.sum + l.rightRun);
        ans.leftRun = max(l.leftRun, l.sum + r.leftRun);
        ans.sum = r.sum + l.sum;
        ans.best = max(max(r.best, l.best), l.rightRun + r.leftRun);
        return ans;
    }

    int maxSubArray_N(vector<int>& nums) {
        int ans = nums[0];
        int run = 0;
        for (int n: nums) {
            run = max(0, run);
            run += n;
            ans = max(ans, run);
        }
        return ans;
    }
};
