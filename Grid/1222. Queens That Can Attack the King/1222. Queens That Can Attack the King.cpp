// problem link: https://leetcode.com/problems/queens-that-can-attack-the-king/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
// brute force
private:
    void attack(vector<vector<int>>& board, vector<int> &k, vector<vector<int>>& res) {
        int n = board.size();
        int m = board[0].size();
        int r = k[0], c = k[1];

        // column left
        while (c >= 0) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            c--;
        }

        r = k[0], c = k[1];
        // column right
        while (c < m) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            c++;
        }

        r = k[0], c = k[1];
        // top
        while (r >= 0) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            r--;
        }

        r = k[0], c = k[1];
        // bottom
        while (r < n) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            r++;
        }

        r = k[0], c = k[1];
        // left upper diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            r--, c--;
        }

        r = k[0], c = k[1];
        // left lower diagonal
        while (r < n && c >= 0) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            r++, c--;
        }

        r = k[0], c = k[1];
        // right upper diagonal
        while (r >= 0 && c < m) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            r--, c++;
        }

        r = k[0], c = k[1];
        // right lower diagonal
        while (r < n && c < m) {
            if (board[r][c] == 1) {
                res.push_back({r, c});
                break;
            }
            r++, c++;
        }
    }

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int>(8, 0));
        vector<vector<int>> directAttackingQueens;
        
        board[king[0]][king[1]] = 2;
        for (auto queen: queens) {
            board[queen[0]][queen[1]] = 1;
        }
        attack(board, king, directAttackingQueens);
        return directAttackingQueens;
    }
};