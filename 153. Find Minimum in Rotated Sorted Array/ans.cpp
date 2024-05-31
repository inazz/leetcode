class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 || nums[0] < nums[nums.size()-1])
            return nums[0];
        int low = 1, high = nums.size()-1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[0] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};
