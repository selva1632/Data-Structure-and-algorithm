// problem link: https://leetcode.com/problems/map-of-highest-peak/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> grid(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + dx[i];
                int c = col + dy[i];

                if (isValid(r, c, n, m) && grid[r][c] == -1) {
                    q.push({r, c});
                    grid[r][c] = grid[row][col] + 1;
                }
            }
        }


        return grid;
    }
private:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
};