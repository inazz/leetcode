class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = (high + low) / 2;
            if (target <= nums[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
