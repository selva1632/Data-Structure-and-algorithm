// problem link:

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
private:
    /*
        time complexity - O(N * M)
        space complexity - O(N * M) + O(M + N)
    */
    int f(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 1;
        }

        if (i < 0 || j < 0) {
            return 0;
        }

        int top = f(i, j-1, dp);
        int left = f(i - 1, j, dp);
        return dp[i][j] = left + top;
    }
public:
    int uniquePaths(int m, int n) {
    //    vector<vector<int>> dp(m, vector<int>(n, 0));
    //    return f(m - 1, n - 1, dp);

    /*
        time complexity - O(N * M)
        space complexity - O(N * M)
    */

       vector<vector<int>> dp(m, vector<int>(n, 0));
       dp[0][0] = 1;

       for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int left = 0, top = 0;
                    if (i > 0) { top = dp[i-1][j]; }
                    if (j > 0) { left = dp[i][j-1]; }
                    dp[i][j] = left + top;
                }
            }
       }
       return dp[m-1][n-1];
    }
};