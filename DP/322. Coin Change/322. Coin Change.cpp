// problem link: https://leetcode.com/problems/coin-change/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
private:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target % coins[0] == 0) return target / coins[0];
            return 1e9;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notpick = f(ind - 1, target, coins, dp);
        int pick = 1e9;
        if (coins[ind] <= target) {
            pick = 1 + f(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n-1, amount, coins, dp);
        return ans >= 1e9 ? - 1: ans;
    }
};  

/*
    Time Complexity: O(n × amount)
    Space Complexity: O(n × amount)
*/