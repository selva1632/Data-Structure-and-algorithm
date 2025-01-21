// problem link: https://leetcode.com/problems/first-completely-painted-row-or-column/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> store(m * n + 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                store[mat[i][j]] = {i, j};
            }
        }

        // vis array
        vector<int> row_tally(n, 0), col_tally(m, 0);

        for (int i = 0; i < arr.size(); i++) {
            int row = store[arr[i]].first;
            int col = store[arr[i]].second;

            // update row
            row_tally[row]++;
            // update column
            col_tally[col]++; 

            if (row_tally[row] == m || col_tally[col] == n) {
                return i;
            }
        }

        return -1;
    }
};