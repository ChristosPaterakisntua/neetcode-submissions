class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = (int)grid.size(), width = (int)grid[0].size();
        int total_islands = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    bfs(i,j, grid, height, width);
                    ++total_islands;
                }
            }
        }
        return total_islands;
    }

    void addNeighbor(int i, int j, vector<vector<char>>& grid, queue<pair<int,int>>& q) {
        if (grid[i][j] != '1') return;
        q.push({i,j});
        grid[i][j] = '0';
    }

    void bfs(int i, int j, vector<vector<char>>& grid, int hBound, int wBound) {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            if (x+1 < hBound) addNeighbor(x+1, y, grid, q);
            if (x-1 >= 0) addNeighbor(x-1, y, grid, q);
            if (y+1 < wBound) addNeighbor(x, y+1, grid, q);
            if (y-1 >= 0) addNeighbor(x, y-1, grid, q);
        }

    }
};
