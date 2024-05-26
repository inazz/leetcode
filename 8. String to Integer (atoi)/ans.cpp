#include <algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        const int64_t NUM_2_31= ((int64_t) 1) << 31;
        int idx = 0;
        // step 1. whitespaces.
        while (idx < s.size() && s[idx] == ' ')
            idx++;
        // step2. signedness
        bool negative = false;
        if (idx < s.size() && s[idx] == '-' || s[idx] == '+') {
            negative = (s[idx++] == '-');
        }
        // step3. conversions.
        int64_t num = 0;
        while (idx < s.size() && '0' <= s[idx] && s[idx] <= '9') {
            num = min(NUM_2_31, num * 10 + (s[idx++] - '0'));
        }
        num *= (negative ? -1 : 1);
        // step4. rounding
        num = min(NUM_2_31-1, max(-NUM_2_31, num));
        return (int) num;
    }
};
