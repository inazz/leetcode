class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sumCount;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k)
                ans++;
            int target = sum-(k-nums[i]);
            auto itr = sumCount.find(target);
            if (itr != sumCount.end())
                ans += itr->second;
            itr = sumCount.find(sum);
            if (itr == sumCount.end()) {
                sumCount[sum] = 1;
            } else {
                itr->second++;
            }
            sum += nums[i];
        }
        return ans;
    }
};
