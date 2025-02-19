// problem link: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{ 
    int f (int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (i < 0 || i >= mat.size()) return INT_MIN;
        
        if (j == 0) {
            return mat[i][j];
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int x = f(i - 1, j - 1, mat, dp);
        int y = f(i, j - 1, mat, dp);
        int z = f(i + 1, j - 1, mat, dp);
        
        return dp[i][j] = mat[i][j] + max({x, y, z});
    }
public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, f(i, m - 1, mat, dp));
        }
        return ans;
    }
};