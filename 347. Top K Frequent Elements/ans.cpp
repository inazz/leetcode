class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() > 10000) {
            return topKFrequent_Bucket(nums, k);
        } else {
            return topKFrequent_NlogN(nums, k);
        }
    }
    vector<int> topKFrequent_Bucket(vector<int>& nums, int k) {
        const int N = 1E4;
        vector<int> counts(2*N+1, 0);
        for (int n: nums)
            counts[N+n]++;
        set<pair<int, int>> topk_set; // pair(count, num)
        for (int i=0; i<counts.size(); i++) {
            if (counts[i] > 0) {
                topk_set.insert(make_pair(counts[i], i-N));
                if (topk_set.size() > k)
                    topk_set.erase(topk_set.begin());
            }
        }
        vector<int> ans;
        for (pair<int, int> p: topk_set)
            ans.push_back(p.second);
        return ans;
    }

    vector<int> topKFrequent_NlogN(vector<int>& nums, int k) {
        map<int, int> counts;
        for (int n: nums) {
            if (counts.find(n) == counts.end()) {
                counts[n] = 1;
            } else {
                counts[n]++;
            }
        }
        vector<pair<int, int>> count_nums;
        for(pair<int,int> c: counts)
            count_nums.push_back(make_pair(c.second, c.first));
        sort(count_nums.begin(), count_nums.end());
        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(count_nums[count_nums.size()-1-i].second);
        return ans;
    }
};
