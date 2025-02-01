// problem link: https://leetcode.com/problems/coin-change-ii/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
private:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (target == 0) {
            return 1;
        }
        if (ind == 0) {
            if (target % coins[ind] == 0) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notpick = f(ind - 1, target, coins, dp);
        int pick = 0;
        if (coins[ind] <= target) {
            pick = f(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, - 1));
        return f(n-1, amount, coins, dp);
    }
};