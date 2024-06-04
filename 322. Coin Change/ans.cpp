class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1, -1);
        ans[0] = 0;
        for (int i=0; i<amount; i++) {
            if (ans[i] == -1)
                continue;
            for (int coin: coins) {
                if (coin <= amount && i+coin <= amount) {
                    ans[i+coin] = (ans[i+coin] == -1 ? ans[i]+1 : min(ans[i+coin], ans[i]+1));
                }
            }
        }
        return ans[amount];
    }
};
