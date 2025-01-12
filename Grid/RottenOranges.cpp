// problem link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        // no fresh orange
        if (fresh == 0)
            return 0;

        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};
        int time = 0;
        
        while(!q.empty()) {
            int size = q.size();
            time++;
            for (int i = 0; i < size; i++) {
                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int r = x + dx[k];
                    int c = y + dy[k];

                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r, c});
                    }
                }
            }
        }

        return fresh > 0 ? - 1: time - 1;
    }
};
