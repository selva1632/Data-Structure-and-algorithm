// problem link: https://leetcode.com/problems/first-completely-painted-row-or-column/

#include<iostream>
#include<vector>
using namespace std;

// this issue can also be solved with DP and Dijkstra's algorithm

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dxy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> q;

        q.push_front({0, 0});
        dis[0][0] = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();

            for (int k = 0; k < 4; k++) {
                int r = x + dxy[k][0];
                int c = y + dxy[k][1];
                int cost = (grid[x][y] != (k + 1)) ? 1 : 0;
                
                if (isValid(r, c, n, m) && dis[x][y] + cost < dis[r][c]) {
                    dis[r][c] = cost + dis[x][y];
                    if (cost == 1) {
                        q.push_back({r, c});
                    } else {
                        q.push_front({r, c});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
private:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
};