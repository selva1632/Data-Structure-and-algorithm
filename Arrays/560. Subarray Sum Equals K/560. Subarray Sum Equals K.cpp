// problem link: https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int subArrays = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum - k;
            subArrays += mpp[rem];
            mpp[sum]++;
        }

        return subArrays;
    }
};