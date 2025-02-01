// problem link: https://leetcode.com/problems/longest-common-subsequence/
 
 #include<iostream>
 #include<vector>
 #include<string>
 using namespace std;

class Solution {
    /*
        time complexity - O(N x M)
        space complexity - O(m × n) (DP Table) + O(m + n) (Recursive Stack) = O(m × n)
    */
private:
    int f(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (text1[i] == text2[j]) 
            return 1 + f(i - 1, j - 1, text1, text2, dp);

        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(f(i, j-1, text1, text2, dp), f(i-1, j, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        // return f(n - 1, m - 1, text1, text2, dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
/*
    time complexity - O(N x M)
    space complexity - O(N x M)
*/