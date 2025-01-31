// problem link: https://leetcode.com/problems/minimum-path-sum/

#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
private:
    /*
        time complexity - O(N * N)
        space complexity - O(N * N) + O(N * N)
    */
    int f(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (x == 0 && y == 0)
            return grid[x][y];

        if (x < 0 || y < 0)
            return INT_MAX;

        if (dp[x][y] != -1)
            return dp[x][y];

        int top = f(x - 1, y, grid, dp);
        int left = f(x, y - 1, grid, dp);

        return dp[x][y] = grid[x][y] + min(top, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m + 1, -1));

        // return f(n - 1, m - 1, grid, dp);
        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i-1][0];
        }

        for (int j = 1; j < m; j++) {
            grid[0][j] += grid[0][j-1];
        }


        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[n-1][m-1];
    }
};

/*
    time complexity - O(N ^ 2)
    space complexity - O(1)
*/