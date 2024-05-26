class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find lowest index to update with next number.
        // -1 if next permutation doesn't exist.
        int midx = ((int)nums.size()) - 2;
        while (midx >= 0 && nums[midx] >= nums[midx+1])
            midx--;
        // update nums[midx] by swapping to the lowest number which is greater than nums[midx].
        // if there is multiple such index, use rightmost one, to keep nums[midx+1:] decreasing order.
        if (midx >= 0) {
            int tidx;
            for (int i = midx +1; i < nums.size(); i++) {
                if (nums[midx] < nums[i]) {
                    tidx = i;
                }
            }
            swap(nums[midx], nums[tidx]);
        }
        // sort nums[midx+1:] by reversing it.
        for (int i=1; midx+i < nums.size()-i; i++) {
            swap(nums[midx+i], nums[nums.size()-i]);
        }
    }
};
