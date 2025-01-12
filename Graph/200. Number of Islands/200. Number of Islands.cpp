/* problem link: https://leetcode.com/problems/number-of-islands */ 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(int x, int y, vector<vector<char>>& grid, int n, int m) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0') 
            return;
        
        grid[x][y] = '0';
        dfs(x + 1, y, grid, n, m);
        dfs(x, y + 1, grid, n, m);
        dfs(x - 1, y, grid, n, m);
        dfs(x, y - 1, grid, n, m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, n, m);
                }
            }
        }

        return count;
    }
};