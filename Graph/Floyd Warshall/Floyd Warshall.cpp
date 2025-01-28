// problem link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1) mat[i][j] = 1e9;
                if (i == j) mat[i][j] = 0; 
            }
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1e9) {
                    mat[i][j] = -1;
                }
            }
        }
    }
};