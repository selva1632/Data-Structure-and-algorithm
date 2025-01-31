// problem link: https://leetcode.com/problems/unique-paths-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int f(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (x < 0 || y < 0 || grid[x][y] == 1) return 0;
        if (x == 0 && y == 0) {
            return 1;
        }

        if (dp[x][y] != -1) return dp[x][y];

        int top = f(x - 1, y, grid, dp);
        int left = f(x, y - 1, grid, dp);
        return dp[x][y] = top + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        return f(n - 1, m - 1, obstacleGrid, dp);
    }
};