// problem link: https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // transpose 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};