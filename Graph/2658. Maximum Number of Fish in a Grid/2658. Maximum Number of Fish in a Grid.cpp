// problem link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;

        int ans = grid[x][y];
        grid[x][y] = 0;
        ans += dfs(x + 1, y, grid) + dfs(x, y - 1, grid) + dfs(x, y + 1, grid) + dfs(x - 1, y, grid);
        return  ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0, cur = 0;


        for (int i = 0; i < n; i++) {   
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;

    }
};