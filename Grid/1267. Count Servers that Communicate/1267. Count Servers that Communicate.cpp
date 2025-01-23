// problem link: https://leetcode.com/problems/count-servers-that-communicate

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int connections = 0;
        vector<int> row(n, 0), col(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                    connections++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (row[i] == 1 && col[j] == 1)) {
                    connections--;
                }
            }
        }
        return connections;
    }
};
