class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int y=0; y<grid.size(); y++)
            for(int x=0; x<grid[y].size(); x++)
                ans = max(ans, sink(x, y, grid));
        return ans;
    }
    int sink(int x, int y, vector<vector<int>>& grid) {
        if (!(0 <= x && x < grid[0].size() && 0 <= y && y < grid.size() && grid[y][x] == 1))
            return 0;
        grid[y][x] = 0;
        return 1 + sink(x-1, y, grid) + sink(x+1, y, grid) + sink(x, y-1, grid) + sink(x, y+1, grid);
    }
};
