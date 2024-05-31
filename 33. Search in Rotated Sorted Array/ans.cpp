class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((nums[low] < nums[mid] && nums[low] <= target && target <= nums[mid]) ||
                (nums[low] == nums[mid] && nums[low] == target) ||
                (nums[low] > nums[mid] && (nums[low] <= target || target <= nums[mid]))) {
               high = mid;
            } else {
                low = mid + 1;
            }
        }
        return (nums[low] == target ? low : -1);
    }
};
