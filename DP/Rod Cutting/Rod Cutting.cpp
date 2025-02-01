// problem link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
  private:
    int f(int ind, int n, vector<int>& price, vector<vector<int>>& dp) {
        if (ind == 0) {
            return price[0] * n;
        }
        
        if (dp[ind][n] != -1) return dp[ind][n];
        
        int notpick = f(ind - 1, n, price, dp);
        int pick = INT_MIN;
        if (ind + 1 <= n) {
            pick = price[ind] + f(ind, n - ind - 1, price, dp);
        }
        return dp[ind][n] = max(pick, notpick);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n - 1, n, price, dp);
    }
};

/*
    time complexity - O(N * N)
    space complexity - O(N * N) + O(N) 
*/

