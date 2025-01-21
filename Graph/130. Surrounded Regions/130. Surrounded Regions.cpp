// problem link: https://leetcode.com/problems/surrounded-regions/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // adding all 'O' from all 4 corners
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') { 
                q.push({i, 0});
                vis[i][0] = 1;
            } 
            if (board[i][m-1] == 'O') {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = 1;
            } 
            if(board[n-1][j] == 'O') {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};

        // traversing from corner 'O'
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            board[x][y] = '1'; // marking it, such that it is from corner 'O'
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = x + dx[k];
                int c = y + dy[k];
                
                if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && vis[r][c] == 0) {
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }

        // not visited part of 'O' are marked as 'X'
        // marking back '1' as 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};