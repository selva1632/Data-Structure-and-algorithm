// problem link: https://leetcode.com/problems/climbing-stairs/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
    
    // recursion + memo
    int f(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = f(n -1, dp) + f (n - 2, dp) % mod;
    }

    // tabulation
    int tab(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i-2];
        }

        return dp[n];
    }


public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1, -1);
        // return f(n, dp);

        // return dp[n];  

        int prev2 = 1;
        int prev1 = 1;

        if (n <= 1) return 1;

        for (int i = 2; i <= n; i++) {
            int temp = ((prev1 % mod) + (prev2 % mod)) % mod;
            prev2 = prev1;
            prev1 = temp;
        } 

        return prev1;
    }
};