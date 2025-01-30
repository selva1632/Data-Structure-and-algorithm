// problem link: https://www.geeksforgeeks.org/problems/minimal-cost/1

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution{
  private:
    int f(int ind, int k, vector<int>& arr, vector<int>& dp) {
        if (ind == 0) {
            return 0;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int ans = 1e9;
        for (int i = ind - k; i < ind; i++) {
            if (i >= 0) {
                ans = min(ans, f(i, k, arr, dp) + abs(arr[i] - arr[ind]));
            }
        }
        return dp[ind] = ans;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return f(n-1, k, arr, dp);
    }
};

/*
    time complexity - O(N * K)
    space complexity - O(N) + O(N)
*/