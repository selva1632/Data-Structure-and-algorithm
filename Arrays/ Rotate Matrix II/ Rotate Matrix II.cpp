// https://www.naukri.com/code360/problems/rotate-matrix_981260?leftPanelTabValue=PROBLEM

#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top < bottom && left < right) {
        int prev = mat[top + 1][left];

        for (int i = left; i <= right; i++) {
            swap(mat[top][i], prev);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            swap(mat[i][right], prev);
        }
        right--;

        for (int i = right; i >= left; i--) {
            swap(mat[bottom][i], prev);
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            swap(mat[i][left], prev);
        }

        left++;

    }
}

/*
    Time Complexity - O(N)
    Space Complexity - O(1)
*/