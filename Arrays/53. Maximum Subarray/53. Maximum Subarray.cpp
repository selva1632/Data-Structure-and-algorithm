// problem link: https://leetcode.com/problems/maximum-subarray/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0], maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};