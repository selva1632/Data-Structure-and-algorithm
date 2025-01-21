// problem link: https://leetcode.com/problems/search-a-2d-matrix/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;

        while (l <= r) {
            int mid = l + (r -l) / 2;

            int num = matrix[mid / m][mid%m];

            if (num == target) {
                return true;
            } else if (num < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};