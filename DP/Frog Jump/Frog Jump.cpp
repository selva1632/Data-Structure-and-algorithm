// problem link:

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
private:
    /*
        time complexity - O(N)
        space complextiy - O(N) + O(N) {dp - array, recursion stack space}
    
    */

    // recursion + memo
    int f(int ind, vector<int>& height, vector<int>& dp) {
        if (ind == 0) {   
            return 0;
        }
        
        if (dp[ind] != -1) return dp[ind];
        
        int step1 = abs(height[ind] - height[ind-1]) + f(ind - 1, height, dp);
        int step2 = 1e9;
        if (ind > 1) {
            step2 = abs(height[ind] - height[ind-2]) + f(ind - 2, height, dp);
        }
        return dp[ind] = min(step1, step2);
    }

  public:
    int minCost(vector<int>& height) {
        // Code here
        // int n = height.size();
        // vector<int> dp(n + 1, -1);
        // return f(n - 1, height, dp);
        
        // tabulation
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        
        for (int i = 1; i < n; i++) {
            int step1 = abs(height[i] - height[i-1]) + dp[i-1];
            int step2 = 1e9;
            if (i > 1) {
                step2 = abs(height[i] - height[i-2]) + dp[i-2];
            }
            dp[i] = min(step1, step2);
        }
        
        return dp[n-1];
    }
};

/*
    time complexity - O(N)
    space complexity - O(N)
*/



