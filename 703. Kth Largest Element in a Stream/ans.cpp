class KthLargest {
  multiset<int> data;
  int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n: nums) {
            add(n);
        }
    }
    
    int add(int val) {
        data.insert(val);
        if (data.size() > k)
            data.erase(data.begin());
        return *(data.begin());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
