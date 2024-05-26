class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        generate(n, 0, &cur, &ans);
        return ans;
    }
    void generate(int open_remains, int num_unclosed, string *cur, vector<string> *out) {
        if (open_remains == 0 && num_unclosed == 0) {
            out->push_back(*cur);
            return;            
        }
        if (open_remains > 0) {
            cur->push_back('(');
            generate(open_remains-1, num_unclosed+1, cur, out);
            cur->pop_back();
        }
        if (num_unclosed > 0) {
            cur->push_back(')');
            generate(open_remains, num_unclosed-1, cur, out);
            cur->pop_back();
        }
    }
};
