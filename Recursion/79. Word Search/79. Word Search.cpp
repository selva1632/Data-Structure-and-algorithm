// problem link: https://leetcode.com/problems/word-search/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private: 
    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string &word) {
        if (ind == word.size()) {
            return true;
        }
        if (i < 0 || i < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[ind]) 
            return false;

        char originalChar = board[i][j];
        board[i][j] = '*';
        if (dfs(i + 1, j, ind + 1, board, word ) || 
            dfs(i , j - 1, ind + 1, board, word) ||
            dfs(i, j + 1, ind + 1, board, word) || 
            dfs(i -1, j, ind + 1, board, word) ) {
                return true;
            }
            
        board[i][j] = originalChar;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};