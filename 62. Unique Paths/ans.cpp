class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(m, 1), next(m, 0);
        for (int y=1; y<n; y++) {
            for (int x=0; x<m; x++) {
                next[x] = cur[x] + (x==0 ? 0 : next[x-1]);
            }
            cur.swap(next);
        }
        return cur[m-1];
    }
};
