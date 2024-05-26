#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string ans = s;
        // consider the zig-zag string as runs of (numRows-1) characters.
        // 0th run (or even numbered run), x-th character is on x-th row.
        // 1st run (or odd numbered run), x-th character is on (numRows-x)-th row

        int write_idx = 0;
        for (int i = 0; i < numRows; i++) {
            for (int n = 0;; n++) { // each run
                int read_idx = 0; // index of s, indicates a character of n-th run which is placed on i-th row (if exists).
                if (n%2 == 0) {
                    if (i == numRows-1)
                        continue;
                    read_idx = n * (numRows-1) + i;
                } else {
                    if (i == 0)
                        continue;
                    read_idx = n * (numRows-1) + (numRows-1-i);
                }
                if (read_idx >= s.size())
                    break;
                ans[write_idx++] = s[read_idx];
            }
        }
        return ans;
    }
};
