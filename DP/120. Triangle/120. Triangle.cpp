// problem link: https://leetcode.com/problems/triangle/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int f(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (x == triangle.size() - 1) {
            return triangle[x][y];
        }

        if (dp[x][y] != -1) return dp[x][y];
        int left = f(x + 1, y, triangle, dp);
        int right = f(x + 1, y + 1, triangle, dp);

        return dp[x][y] = triangle[x][y] + min(left, right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(i + 1, -1);
        }
        return f(0, 0, triangle, dp);
    }
};

/*
    time complexity -  O(N ^ 2)
    space complexity - O(N ^ 2)
*/