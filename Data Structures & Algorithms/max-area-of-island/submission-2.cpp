class Solution {
private:
    int calc_flat_pos_and_zero(int i, int j, int n, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        return i * n + j;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = (int)grid.size(); // rows
        int n = (int)grid[0].size(); // cols

        int max_area = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (grid[i][j] == 0) continue;

                int flat_pos = calc_flat_pos_and_zero(i, j, n, grid);
                
                queue<int> q;
                q.push(flat_pos);

                int cur_area = 0;

                while (!q.empty()) {
                    int cur_pos = q.front();
                    q.pop();
                    int cur_i = cur_pos / n;
                    int cur_j = cur_pos % n;

                    ++cur_area;

                    grid[cur_i][cur_j] = 0;

                    if (cur_i + 1 < m && grid[cur_i+1][cur_j]) {
                        q.push(calc_flat_pos_and_zero(cur_i+1, cur_j, n, grid));
                    }

                    if (cur_i - 1 >= 0 && grid[cur_i-1][cur_j]) {
                        q.push(calc_flat_pos_and_zero(cur_i-1, cur_j, n, grid));
                    }

                    if (cur_j + 1 < n && grid[cur_i][cur_j+1]) {
                        q.push(calc_flat_pos_and_zero(cur_i, cur_j+1, n, grid));
                    }

                    if (cur_j - 1 >= 0 && grid[cur_i][cur_j-1]) {
                        q.push(calc_flat_pos_and_zero(cur_i, cur_j-1, n, grid));
                    }
                }

                max_area = max(max_area, cur_area);
            }
        }

        return max_area;
    }
};
