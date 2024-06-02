class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size(), w = obstacleGrid[0].size();
        vector<vector<int>> ans(h, vector<int>(w, 0));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (obstacleGrid[y][x]) {
                    ans[y][x] = 0;
                } else if (x == 0 && y == 0) {
                    ans[y][x] = 1;
                } else {
                    ans[y][x] = ((y == 0 ? 0 : ans[y-1][x]) +
                                 (x == 0 ? 0 : ans[y][x-1]));
                }
            }
        }
        return ans[h-1][w-1];
    }
};
