// problem link: https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 0)); // result
        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited array
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            
            q.pop();
            dist[x][y] = d;

            for (int k = 0; k < dir.size(); k++) {
                int r = x + dir[k][0];
                int c = y + dir[k][1];

                if (r >= 0 && c >= 0 && r < n && c < m && vis[r][c] == 0) {
                    vis[r][c] = 1;
                    dist[r][c] = d + 1;
                    q.push({{r, c}, d + 1});
                }
            }
        }
        return dist;
    }
};