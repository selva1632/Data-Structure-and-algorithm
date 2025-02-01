// problem link: https://leetcode.com/problems/partition-equal-subset-sum

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
private:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>> &dp) {
        if (ind == 0) {
            if (target == nums[0]) {
                return true;
            }
            return false;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notpick = f(ind - 1, target, nums, dp);
        bool pick = false;
        if (nums[ind] <= target) {
            pick = f(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = pick || notpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        return f(n - 1, sum / 2, nums, dp);
    }
};

/*
    time complexity - O(n * sum)
    space complexity -  O(n * sum) + O(N)
*/