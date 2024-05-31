class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_capacity = 1;
        while (!testShippable(weights, max_capacity, days)) {
            max_capacity *= 2;
        }
        int min_capacity = (max_capacity == 1 ? 1 : max_capacity / 2);
        while (min_capacity < max_capacity) {
            int mid_capacity = (min_capacity + max_capacity) / 2;
            if (testShippable(weights, mid_capacity, days)) {
                max_capacity = mid_capacity;
            } else {
                min_capacity = mid_capacity + 1;
            }
        }
        return min_capacity;
    }
    bool testShippable(const vector<int>& weights, int capacity, int days) {
        int weight_loaded = 0;
        int current_day = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > capacity)
                return false;
            if (weight_loaded + weights[i] > capacity) {
                current_day++;
                weight_loaded = weights[i];
            } else {
                weight_loaded += weights[i];
            }
        }
        if (weight_loaded > 0)
            current_day++;
        return (current_day <= days);
    }
};
