// problem link: https://leetcode.com/problems/making-a-large-island/

#include <vector> 
#include <unordered_map>
#include <set> 
#include <algorithm>  
using namespace std;

class Solution {
private:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    bool isvalid(int r, int c, int n) {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }

    int dfs(int x, int y, vector<vector<int>>& grid, int n, int uId) {
        grid[x][y] = uId; // marking island node with uId
        int count = 1;

        for (int i = 0; i < 4; i++) {
            int r = x + dx[i];
            int c = y + dy[i];

            if (isvalid(r, c, n) && grid[r][c] == 1) {
                count += dfs(r, c, grid, n, uId);
            }
        }
        return count; // return size of island
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mpp; // store uId - size of island
        int uId = 2;                 // unique id for each island

        // marking of Island:  O(N * N)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = dfs(i, j, grid, n, uId);
                    mpp[uId] = count;
                    uId++;
                }
            }
        }

        set<int> island;
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    island.clear();

                    // checking the 4 direction if any island is present
                    for (int k = 0; k < 4; k++) {
                        int r = i + dx[k];
                        int c = j + dy[k];

                        if (isvalid(r, c, n)) {
                            island.insert(grid[r][c]);
                        }
                    }

                    // calculate max area by marking the zero as 1
                    int curArea = 1;
                    for (auto it : island) {
                        curArea += mpp[it];
                    }

                    area = max(area, curArea);
                }
            }
        }

        return area == 0 ? n * n : area;
    }
};

/*
    time complexity - O(N^2) + O(N ^ 2) => O(N^2)
    space complexity - O(N^2) + O(N^2) => O(N^2)  // recursion stack space & unordered_map in worst case

*/