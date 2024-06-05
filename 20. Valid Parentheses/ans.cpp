class Solution {
public:
    bool isValid(string s) {
        deque<char> q;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                q.push_back((c == '(' ? ')' : (c == '{' ? '}' : ']')));
            } else if (q.empty() || q.back() != c) {
                return false;
            } else {
                q.pop_back();
            }
        }
        return q.empty();
    }
};
