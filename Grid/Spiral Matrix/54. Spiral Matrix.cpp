//problem link: https://leetcode.com/problems/spiral-matrix/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, top = 0;
        int bottom = n - 1, r = m - 1;
        vector<int> res;
        while (l <= r && top <= bottom) {

            // left to right
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // top to bottom
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][r]);
            }
            r--;

            // right to left 
            if (top <= bottom){
                for (int i = r; i >= l; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            if (l <= r) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};