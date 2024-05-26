class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sidx=0;
        for (int tidx=0; tidx < t.size(); tidx++) {
            if (s[sidx] == t[tidx]) {
                sidx++;
                if (sidx == s.size())
                    return true;
            }
        }
        return false;
    }
};
