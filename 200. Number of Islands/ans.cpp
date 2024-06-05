class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int y=0; y<grid.size(); y++) {
            for(int x=0; x<grid[y].size(); x++) {
                if (grid[y][x] != '1')
                    continue;
                ans += 1;
                sink(x, y, grid);
            }
        }
        return ans;
    }
    void sink(int x, int y, vector<vector<char>> &grid) {
        if (grid[y][x] != '1')
            return;
        grid[y][x] = '0';
        if (x != 0)
            sink(x-1, y, grid);
        if (x != grid[0].size()-1)
            sink(x+1, y, grid);
        if (y != 0)
            sink(x, y-1, grid);
        if (y != grid.size()-1)
            sink(x, y+1, grid);
    }
};
