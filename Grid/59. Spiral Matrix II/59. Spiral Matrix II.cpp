// problem link: https://leetcode.com/problems/spiral-matrix-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int j = 1;
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                res[top][i] = j;
                j++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                res[i][right] = j;
                j++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res[bottom][i] = j;
                    j++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = j;
                    j++;
                }
                left++;
            }
        }
        return res;
    }
};