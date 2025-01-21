// problem link: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size() - 1;
        int n = matrix.size(); 
        while (r < n && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                r++;
            } else {
                c--;
            }
        }
        return false;
    }
};