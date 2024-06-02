class Solution {
public:
    int rob(vector<int>& nums) {
        int amountIfPrevRobbed = 0, amountIfPrevNotRobbed = 0;
        for (int n: nums) {
            int amountIfThisRobbed = amountIfPrevNotRobbed + n;
            int amountIfThisNotRobbed = max(amountIfPrevRobbed, amountIfPrevNotRobbed);
            amountIfPrevRobbed = amountIfThisRobbed;
            amountIfPrevNotRobbed = amountIfThisNotRobbed;
        }
        return max(amountIfPrevRobbed, amountIfPrevNotRobbed);
    }
};
