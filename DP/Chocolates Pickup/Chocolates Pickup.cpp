// problem link: https://www.geeksforgeeks.org/problems/chocolates-pickup/1

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
  private:
    int f(int x, int y1, int y2, vector<vector<int>>& grid, int n, int m, 
    vector<vector<vector<int>>>& dp) {
        if (y1 < 0 || y2 < 0 || y1 >= m || y2 >= m) {
            return INT_MIN;
        }
        
        if (x == n - 1) {
            if (y1 == y2) {
                return grid[x][y1];
            }
            return grid[x][y1] + grid[x][y2];
        }
        
        if (dp[x][y1][y2] != -1) {
            return dp[x][y1][y2];
        }
        
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int temp = 0;
                if (y1 == y2) {
                    temp = grid[x][y1];
                } else {
                    temp = grid[x][y1] + grid[x][y2];
                }
                temp += f(x + 1, y1 + i, y2 + j, grid, n, m, dp);
                ans = max(temp, ans);
            }
        }
        return dp[x][y1][y2] = ans;
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m + 1, -1)));
        return f(0, 0, m-1, grid, n, m, dp);
    }
};

/*
    time complexity - O(N * M * M) * 9
    space complexity - O(N * M * M) + O(N)
*/