class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charCount('z'-'a'+1, 0);
        for (char c: s)
            charCount[c-'a']++;
        for (int i=0; i<s.size(); i++)
            if (charCount[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};
