class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) { 
                q.push({i, 0});
                vis[i][0] = 1;
            } 
            if (grid[i][m-1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            } 
            if(grid[n-1][j] == 1) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            grid[x][y] = 0;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = x + dx[k];
                int c = y + dy[k];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && vis[r][c] == 0) {
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }

        int island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    island++;
                }
            }
        }
        return island;
    }
};