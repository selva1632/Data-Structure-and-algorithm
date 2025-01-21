// problem link: https://leetcode.com/problems/n-queens/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int& n) {
        int dRow = row, dCol = col;

        // check that column
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        row = dRow, col = dCol;

        // upper diagonal check for Queen
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        row = dRow, col = dCol;

        // lower diagonal check for Queen

        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    void f(int col, int& n, vector<string>& board,
           vector<vector<string>>& res, vector<int> &left, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
//            if (isSafe(row, col, board, n)) {
                if (left[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0) {
                left[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n - 1 + col - row] = 1;
                board[row][col] = 'Q';
                f(col + 1, n, board, res, left, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                left[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n - 1 + col - row] = 0;
                }
//            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string temp(n, '.');
        for (int i = 0; i < n; i++) {
            board.push_back(temp);
        }

        vector<int> left(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        f(0, n, board, res, left, upperDiagonal, lowerDiagonal);
        return res;
    }
};