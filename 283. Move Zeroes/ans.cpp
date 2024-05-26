class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num_zeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                num_zeros++;
            } else if (num_zeros > 0) {
                swap(nums[i-num_zeros], nums[i]);
            }
        }
    }
};
