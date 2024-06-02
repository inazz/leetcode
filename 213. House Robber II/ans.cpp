class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // first y/n means house at index 0 is robbed.
        // second y/n means house at previous index is robbed.
        int yy = nums[0], yn = 0, ny = 0, nn = 0;
        for (int i = 1; i < nums.size(); i++) {
            int cyy = yn + nums[i];
            int cyn = max(yy, yn);
            int cny = nn + nums[i];
            int cnn = max(ny, nn);
            yy = cyy;
            yn = cyn;
            ny = cny;
            nn = cnn;
        }
        return max(yn, ny);
    }
};
