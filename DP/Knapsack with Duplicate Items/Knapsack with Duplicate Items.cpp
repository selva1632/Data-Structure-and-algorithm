// problem link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
  private:
    int f(int ind, int cap, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp) {
        if (ind == 0) {
            if (wt[0] <= cap) {
                return ((int) (cap / wt[0]) * val[0]);
            }
            return 0;
        }
        
        if (dp[ind][cap] != -1) return dp[ind][cap];
        
        int notpick = f(ind - 1, cap, val, wt, dp);
        int pick = 0;
        if (wt[ind] <= cap) {
            pick = val[ind] + f(ind, cap - wt[ind], val, wt, dp);
        }
        
        return dp[ind][cap] = max(notpick, pick);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>> dp(val.size(), vector<int>(capacity + 1, -1));
        return f(val.size() - 1, capacity, val, wt, dp);
    }
};

/*
    k - capacity
    time complexity - O(N * K)
    space complexity - O(N * K) + O(N)
*/

