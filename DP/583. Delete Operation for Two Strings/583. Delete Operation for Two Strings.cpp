// problem link: https://leetcode.com/problems/delete-operation-for-two-strings/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return n - dp[n][m] + m - dp[n][m];
    }
};

/*
    time complexity - O(N * M)
    space complextity - O(N * M)
*/