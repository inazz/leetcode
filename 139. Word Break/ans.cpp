class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // possible[n] is true iff wordBrake(s.substring(0, n), wordDict) is true.
        vector<bool> possible(s.size()+1, false);
        possible[0] = true;
        for(int i=0; i<s.size(); i++) {
            if (!possible[i])
                continue;
            for (const string &word: wordDict) {
                if (word.size() + i > s.size())
                    continue;
                bool match = true;
                for (int j=0; j<word.size(); j++) {
                    if (s[i+j] != word[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    possible[i+word.size()] = true;
                }
            }
        }
        return possible[s.size()];
    }
};
