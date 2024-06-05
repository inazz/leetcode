class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        for(const string &email: emails)
            uniqueEmails.insert(normalize(email));
        return uniqueEmails.size();
    }
    string normalize(const string &email) {
        string s;
        bool skip = false;
        for (int i=0; i<email.size(); i++) {
            if (email[i] == '@') {
                s += email.substr(i);
                break;
            }
            if (skip || email[i] == '.')
                continue;
            if (email[i] == '+') {
                skip = true;
            } else {
                s.push_back(email[i]);
            }
        }
        return s;
    }
};
