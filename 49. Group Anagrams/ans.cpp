class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, int> sortedToAnsIdx;
        for(const string &str: strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            map<string, int>::iterator itr = sortedToAnsIdx.find(sorted);
            int idx = ans.size();
            if (itr != sortedToAnsIdx.end()) {
                idx = itr->second;
            } else {
                sortedToAnsIdx.insert(make_pair(sorted, idx));
                ans.push_back(vector<string>());
            }
            ans[idx].push_back(str);
        }
        return ans;
    }
};
