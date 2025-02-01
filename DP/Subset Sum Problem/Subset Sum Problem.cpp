// problem link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        bool f(int ind, vector<int>& arr, int target, vector<vector<int>> &dp) {
            if (target == 0) return true;
            if (ind < 0 || target < 0) return false;
            if (dp[ind][target] != -1) return dp[ind][target];
            
            return dp[ind][target] = f(ind - 1, arr, target, dp) || 
                    f(ind - 1, arr, target - arr[ind], dp);
        }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, arr, target, dp);
    }
};

/*
    time complexity - O(2 ^ N)
    space complexity - O(N) + O(N)
*/

