// problem link: https://leetcode.com/problems/house-robber/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
private:
    /*
        time complexity - O(N)
        space complexity - O(N) + O(N)
    */

    // recursion + memo
    int f(int ind, vector<int>& arr, vector<int>& dp) {
        if (ind == 0) return arr[0];

        if (dp[ind] != -1) return dp[ind];

        int step1 = 0 + f(ind - 1, arr, dp);
        int step2 = 0;
        if (ind > 1) {
            step2 = arr[ind] + f(ind - 2, arr, dp);
        }
        return dp[ind] = max(step1, step2);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(n - 1, nums, dp);

        // tabulation
        /*
            time complexity - O(N)
            space complexity - O(N)
        */
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int step1 = dp[i-1];
            int step2 = dp[i-2] + nums[i];

            dp[i] = max(step1, step2);
        }
        return dp[n-1];

        // space optimization
        /*
            time complexity - O(N)
            space complexity - O(1)
        */
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }   
        return prev1;
    }
};